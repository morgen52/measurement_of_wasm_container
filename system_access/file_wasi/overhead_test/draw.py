import re
import json
import matplotlib.pyplot as plt

LOG_DIR = "measured_results/logs"
RESULT_DIR = "measured_results"
FIG_DIR = "figures"

def handle_time(t): # transform time to ms
    if t.endswith("ms"): 
        return float(t[:-2])
    elif t.endswith("µs"):
        return float(t[:-2]) / 1000
    elif t.endswith("s"):
        return float(t[:-1]) * 1000
    else:
        assert False, "unknown time unit"

def transfer_handler(save_name):
    with open(f"{LOG_DIR}/{save_name}", "r", encoding="utf8") as f:
        log = f.readlines()
    times = {"create": [], "read": [], "delete": []}
    for line in log: 
        t = re.findall(r"\d+\.\d+[m|µ]?s", line)
        if t:
            k = re.findall(r"create|read|delete", line)[0]
            times[k].append(handle_time(t[0]))
    with open(f"{LOG_DIR}/{save_name.replace('.txt', '.json')}", 'w', encoding="utf8") as f:
        json.dump(times, f, indent=4)

def log_transfer():
    # log data transfer to structured json
    runtimes = ["wasmtime", "wasmer"]
    for r in runtimes:
        transfer_handler(f"log_wasm_vm_{r}.txt")
        transfer_handler(f"log_wasm_container_{r}.txt")
    transfer_handler(f"log_native.txt")
    transfer_handler(f"log_native_container.txt")

def get_results(runtime="wasmer"):
    with open(f"{LOG_DIR}/log_wasm_container_{runtime}.json", "r", encoding="utf8") as f1,\
        open(f"{LOG_DIR}/log_native_container.json", "r", encoding="utf8") as f2,\
        open(f"{LOG_DIR}/log_wasm_vm_{runtime}.json", "r", encoding="utf8") as f3:
        wasm_docker = json.load(f1)
        native_docker = json.load(f2)
        native_wasm = json.load(f3)

    results = {"read": {}, "create": {}, "delete": {}}
    for k in results.keys():
        results[k]["wasm"] = {
            "execution": sum(wasm_docker[k]) / len(wasm_docker[k])
        }
        results[k]["native"] = {
            "execution": sum(native_docker[k]) / len(native_docker[k])
        }
        results[k]["native_wasm"] = {
            "execution": sum(native_wasm[k]) / len(native_wasm[k])
        }

    with open(f"{RESULT_DIR}/results_{runtime}.json", "w", encoding="utf8") as f:
        json.dump(results, f, indent=2)

def draw(runtime="wasmer"):
    
    with open(f"{RESULT_DIR}/results_{runtime}.json", "r") as f:
        result = json.load(f)
    x_label = ['read', 'write', 'delete']
    x = [ "read", "create", "delete"]
    x_loc = [i for i in range(len(x))]
    
    native_execution = [result[i]['native']['execution'] for i in x]
    wasm_execution = [result[i]['wasm']['execution'] for i in x]
    nativewasm_execution = [result[i]['native_wasm']['execution'] for i in x]

    WIDTH = 0.2
    plt.figure(figsize=(9, 3))
    plt.bar([i - WIDTH for i in x_loc], native_execution, width=WIDTH, label="linux container", color="black")
    plt.bar([i for i in x_loc], wasm_execution, width=WIDTH, label="wasm container", edgecolor="black", color="white", hatch='//')
    plt.bar([i + WIDTH for i in x_loc], nativewasm_execution, width=WIDTH, label="wasm vm", edgecolor="black", color="white", hatch='\\')

    # add value on the top of the bar
    for i, v in enumerate(native_execution):
        plt.text(i - WIDTH, v, f"{v:.3f}", ha='center', va='bottom')
    for i, v in enumerate(wasm_execution):
        plt.text(i, v, f"{v:.3f}", ha='center', va='bottom')
    for i, v in enumerate(nativewasm_execution):
        plt.text(i + WIDTH, v, f"{v:.3f}", ha='center', va='bottom')

    plt.xticks(x_loc, x_label, fontsize=15)
    plt.yticks(fontsize=15)
    plt.ylabel("time(ms)", fontsize=15)
    plt.legend(fontsize=15)

    plt.savefig(f"{FIG_DIR}/file_{runtime}.pdf", bbox_inches='tight', format='pdf')
    plt.clf()

if __name__ == "__main__":
    log_transfer()

    runtimes = ["wasmtime", "wasmer"]
    for r in runtimes:
        get_results(r)
        draw(r)



    

    
    