import os
import time
import json
import datetime
import docker
from tqdm import tqdm

from utils.benchmarks import get_configs
from utils.configs import docker_url

client = docker.DockerClient(base_url=docker_url)
ITERATION = 20
SAVE_DIR = "measured_results"

def time_duration(start_time, end_time):
    start_time = datetime.datetime.strptime(start_time, '%M:%S.%f')
    end_time = datetime.datetime.strptime(end_time, '%M:%S.%f')
    ms = (end_time - start_time).total_seconds() * 1000

    if ms < 0: # over hour points
        ms += 60 * 60 * 1000
    if ms < 0: # over day points
        ms += 23 * 60 * 60 * 1000
    return ms

def run_docker(mode, image, runtime="wasmer"):
    startup_time = 0.0
    compute_time = 0.0
    e2e_time = 0.0

    start_time = datetime.datetime.now().strftime('%M:%S.%f')
    if mode == "wasm":
        container = client.containers.run(f"{image}", runtime=f"io.containerd.{runtime}.v1", platform="wasi/wasm").decode('utf-8')
    elif mode == "native":
        container = client.containers.run(f"{image}").decode('utf-8')
    else:
        assert False, "Invalid mode"
    
    rs = container.strip().split("\n")
    start_compl_time = rs[0].strip().split("time:")[1]
    end_compl_time = datetime.datetime.now().strftime('%M:%S.%f')
    
    try:
        compute_time = float(rs[1].strip()) * 1000
    except:
        breakpoint()
    startup_time = time_duration(start_time, start_compl_time)
    e2e_time = time_duration(start_time, end_compl_time) 

    return startup_time, compute_time, e2e_time

def single_wasm(f, runtime):
    version = "0.1"
    fname = f['result'].split("/")[-1]
    startup_time, compute_time, e2e_time = run_docker("wasm", f"liminfinity/{fname}:{version}", runtime)
    return startup_time, compute_time, e2e_time

def single_native(f, runtime):
    version = "0.0"
    fname = f['result'].split("/")[-1]
    startup_time, compute_time, e2e_time = run_docker("native", f"liminfinity/{fname}:{version}", runtime)
    return startup_time, compute_time, e2e_time

def experiments(flst, spec_bench, runtime=""):
    time_dic = {}
    iteration = ITERATION

    if runtime:
        log_file = f"{SAVE_DIR}/docker_time_result.json.{runtime}"
    else:
        log_file = f"{SAVE_DIR}/docker_time_result.json"

    if spec_bench:
        with open(log_file, "r", encoding="utf-8") as f:
            time_dic = json.load(f)

    print(f"benches: {[f['result'].split('/')[-1] for f in flst]}")
    for f in flst:
        fname = f['result'].split("/")[-1]
        if spec_bench and (fname not in spec_bench):
            continue
        
        time_dic[fname] = {"native": [], "wasm": []}

        for _ in tqdm(range(iteration), desc=f"{fname} {flst.index(f)}/{len(flst)}"):
            time.sleep(1)
            stnative, etnative, rtnative = single_native(f, runtime)
            time_dic[fname]['native'].append({
                'startup': stnative,
                'compute': etnative,
                'e2e': rtnative
            })
            time.sleep(1)
            stwasm, etwasm, rtwasm = single_wasm(f, runtime)
            time_dic[fname]['wasm'].append({
                'startup': stwasm,
                'compute': etwasm,
                'e2e': rtwasm
            })

            os.system("docker rm $(docker ps -aq)")

        time_dic[fname]['native'] = {
            'startup': sum([t['startup'] for t in time_dic[fname]['native']]) / iteration,
            'compute': sum([t['compute'] for t in time_dic[fname]['native']]) / iteration,
            'e2e': sum([t['e2e'] for t in time_dic[fname]['native']]) / iteration
        }
        
        time_dic[fname]['wasm'] = {
            'startup': sum([t['startup'] for t in time_dic[fname]['wasm']]) / iteration,
            'compute': sum([t['compute'] for t in time_dic[fname]['wasm']]) / iteration,
            'e2e': sum([t['e2e'] for t in time_dic[fname]['wasm']]) / iteration
        }

        with open(log_file, "w", encoding="utf8") as f:
            json.dump(time_dic, f, indent=4)

import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-b", "--benchmarks", nargs="+", help="Specify benchmarks to run")
    parser.add_argument("-r", "--runtime", help="Specify runtime to use")

    args = parser.parse_args()
    if args.benchmarks:
        spec_bench = args.benchmarks # e.g. 2mm, 3mm, gemm
    else:
        spec_bench = None
    
    runtime = args.runtime

    allfiles = get_configs()
    # (1) correlation, (2) covariance, (3) 2mm, (4) 3mm, (5) atax, (6) bicg, (7) doitgen, (8) mvt, (9) gemm, (10) gemver, (11) gesummv, (12) symm, (13) syr2k, (14) syrk, (15) trmm, (16) cholesky, (17) durbin, (18) gramschmidt, (19) lu, (20) ludcmp, (21) trisolv, (22) deriche, (23) floyd-warshall, (24) nussinov, (25) adi, (26) fdtd-2d, (27) heat-3d, (28) jacobi-1d, (29) jacobi-2d, (30) seidel-2d

    runtimes = []
    if runtime:
        runtimes.append(runtime)
    else:
        runtimes = ["wasmtime", "wasmer"]

    for r in runtimes:
        print(r)
        experiments(allfiles, spec_bench, r)
