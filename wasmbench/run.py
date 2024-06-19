import os
import json
import docker
import datetime
import time

from tqdm import tqdm

from utils.configs import docker_url

client = docker.DockerClient(base_url=docker_url)
COMPILE_DIR = "compiled"
LOG_DIR = "measured_results"
ELOG_DIR = "error_logs"

def time_duration(start_time, end_time):
    start_time = datetime.datetime.strptime(start_time, '%M:%S.%f')
    end_time = datetime.datetime.strptime(end_time, '%M:%S.%f')
    ms = (end_time - start_time).total_seconds() * 1000

    if ms < 0: # cross an hour
        ms += 3600 * 1000
    if ms < 0: # cross a day
        ms += (24 - 1) * 3600 * 1000
    return ms

def single_experiment(mode, file, runtime="wasmer"):
    start_time = datetime.datetime.now().strftime('%M:%S.%f')
    container = ""
    if mode == "wasm": # run wasm native
        try:
            container = os.popen(f"{runtime} {COMPILE_DIR}/{file}/{file}.wasm").read(32)
        except Exception as e:
            print(file)
            print(e)
    elif mode == "wasm_container":
        try:
            container = client.containers.run(f"wasmbench/{file}:0.1", runtime=f"io.containerd.{runtime}.v1", platform="wasi/wasm32").decode("utf-8")
        except Exception as e:
            print(file)
            print(e)
    elif mode == "linux_container":
        try:
            container = client.containers.run(f"wasmbench/{file}:0.0").decode("utf-8")
        except Exception as e:
            print(file)
            print(e)
    end_compl_time = datetime.datetime.now().strftime('%M:%S.%f')

    start_compl_time = container.split("\n")[0].split("time:")[-1]

    if mode == "wasm_container" or mode == "linux_container":
        client.containers.prune()
    
    try:
        result = { # ms
            "startup": time_duration(start_time, start_compl_time),
            "e2e": time_duration(start_time, end_compl_time),
        }
    except:
        with open(f"{ELOG_DIR}/error.log.{runtime}", "a") as f:
            f.write(f"{file}\n")
        result = {
            "startup": -1,
            "e2e": -1,
        }
    time.sleep(3)
    return result

def experiments(runtime="wasmer"):
    files = sorted(os.listdir(COMPILE_DIR))
    
    logfile = f"{LOG_DIR}/results.json.{runtime}"
    if not os.path.exists(logfile):
        results = {}
    else:
        with open(logfile, "r") as f:
            results = json.load(f)
    
    repeat = 2
    for idx in tqdm(range(len(files))):
        file = files[idx]

        # find the checkpoint
        if file in results.keys():
            for k in results[file].keys():
                if results[file][k]["startup"] == -1:
                    break
            else:
                continue

        print(f"Running {file}...")
        tmp_result = []
        for _ in range(repeat):
            tmp_result.append({
                "wasm": single_experiment("wasm", file, runtime),
                "wasm_container": single_experiment("wasm_container", file, runtime),
                "linux_container": single_experiment("linux_container", file, runtime)
            })

        results[file] = {"wasm": {}, "wasm_container": {}, "linux_container": {}}
        for k in results[file].keys():
            results[file][k] = {
                "startup": sum([item[k]["startup"] for item in tmp_result]) / repeat,
                "e2e": sum([item[k]["e2e"] for item in tmp_result]) / repeat,
            }

        with open(logfile, "w") as f:
            json.dump(results, f, indent=2)

if __name__ == "__main__":
    runtimes = ["wasmtime", "wasmer"]
    for r in runtimes:
        experiments(r)

        


            
