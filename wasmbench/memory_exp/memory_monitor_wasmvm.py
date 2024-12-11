import json
from tqdm import tqdm
import os
import time
import argparse

from utils.resource_monitor import resource_monitor

COMPILE_DIR = "../compiled"
LOG_DIR = "measured_results"

def run_containers(image, mode, runtime="wasmer"):
    concurrent = 10
    containers = []
    cpus = []
    memories = []
    for i in range(concurrent):
        container = None
        if mode == "native_wasm":
            print(f"{runtime} {COMPILE_DIR}/{image}/{image}.wasm")
            container = os.popen(f"{runtime} {COMPILE_DIR}/{image}/{image}.wasm")
        else:
            raise ValueError("mode should be native_wasm")

        if container is not None:
            containers.append(container)
        print(f"running {i+1}/{concurrent} containers, {len(containers)} containers are running ...")
    cpu, memory = resource_monitor(0.5, 1)
    cpus.append(cpu)
    memories.append(memory)
    return max(cpus), max(memories)

def cool():
    time.sleep(1)
    return True
    
def single_experiment(fname, mode, runtime="wasmer"):
    print(f"running {fname} in {mode} ({runtime})...")

    while not cool():
        print("cooling down...")
        time.sleep(1)

    tmp = {
        "before": {},
        "execute": {}
    }
    print(f"checking before ...")
    cpu, mem = resource_monitor(0.5, 5)
    tmp["before"]["cpu"] = cpu
    tmp["before"]["memory"] = mem
    print("start running containers")
    cpu, mem = run_containers(fname, mode, runtime)
    tmp["execute"]["cpu"] = cpu
    tmp["execute"]["memory"] = mem

    print("check execution ...")
    cpu, mem = resource_monitor(0.5, 2)
    tmp["execute"]["cpu"] = max(tmp["execute"]["cpu"], cpu)
    tmp["execute"]["memory"] = max(tmp["execute"]["memory"], mem)
    
    print("cleaning up ...")
    time.sleep(1)
    return tmp

def experiment(key="", runtime="wasmer"):
    funcs = []
    if key == "":
        funcs = os.listdir(COMPILE_DIR)
    else:
        funcs = [key]

    logfile = f"{LOG_DIR}/results_wasmvm.json.{runtime}"
    
    results_nativewasm = {}
    if os.path.exists(logfile):
        with open(logfile, 'r', encoding='utf-8') as f:
            results_nativewasm = json.load(f)
    
    for fname in tqdm(funcs):
        if fname in results_nativewasm: continue
        
        results_nativewasm[fname] = {
            "native_wasm": single_experiment(fname, "native_wasm", runtime)
        }
        with open(logfile, 'w', encoding='utf-8') as f:
            json.dump(results_nativewasm, f, indent=2)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--key", type=str, default="")
    parser.add_argument("--warmup", type=int, default=0)
    parser.add_argument("--runtime", type=str, default="wasmer", choices=["wasmer", "wasmtime"])
    args = parser.parse_args()
    key = args.key
    warmup = args.warmup
    runtime = args.runtime

    if warmup > 0:
        print("warmup...")
        single_experiment(key, "native_wasm", runtime)
    experiment(key, runtime)














    
