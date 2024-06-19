import json
import matplotlib.pyplot as plt


def get_results(runtime=""):

    if runtime:
        runtime = f"_{runtime}"
    
    with open(f"./results/wasm_docker{runtime}.json", "r", encoding="utf8") as f1,\
        open(f"./results/native_docker.json", "r", encoding="utf8") as f2,\
        open(f"./results/wasm_native{runtime}.json", "r", encoding="utf8") as f3:
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

    with open(f"results{runtime}.json", "w", encoding="utf8") as f:
        json.dump(results, f, indent=2)

def draw_results(mode="simple", runtime=""):

    if runtime:
        runtime=f"_{runtime}"
    
    # 1. draw a figure that has two-y-axis
    # ax1 is the bar of execution time of each image
    # ax2 is the plot the relative speedup of each image

    with open(f"results{runtime}.json", "r") as f:
        result = json.load(f)
    x_label = ['read', 'write', 'delete']
    x = [ "read", "create", "delete"]

    x_loc = [i for i in range(len(x))]
    
    native_execution = [result[i]['native']['execution'] for i in x]
    wasm_execution = [result[i]['wasm']['execution'] for i in x]

    speed_up = [wasm_execution[i]/native_execution[i] for i in range(len(x))]
    print(f"{runtime[1:]}: speed up for read, write, delete, respectively: {speed_up}")
    absolute = [wasm_execution[i] - native_execution[i] for i in range(len(x))]
    print(f"{runtime[1:]}: absolute difference for read, write, delete respectively: {absolute}")

    WIDTH = 0.2

    plt.figure(figsize=(9, 3))
    plt.bar([i - WIDTH for i in x_loc], native_execution, width=2*WIDTH, label="linux container", color="black")
    # draw a line to separate native and wasm
    plt.bar([i + WIDTH for i in x_loc], wasm_execution, width=2*WIDTH, label="wasm container", edgecolor="black", color="white", hatch='//')

    plt.xticks(x_loc, x_label, fontsize=15)
    plt.yticks(fontsize=15)
    plt.ylabel("time(ms)", fontsize=15)
    # plt.xlabel("benchmarks", fontsize=15)
    # plt.grid(True, axis='x', color="white")

    plt.legend(fontsize=15)
    # plt.savefig(f"./time_absolute{runtime}.png", bbox_inches='tight')
    # plt.clf()

    # draw relative
    ax2 = plt.twinx()    
    ax2.plot(x_loc, [wasm_execution[i]/native_execution[i] for i in range(len(x))], label="execution", marker='*', color='#929AAB', linewidth=2, markersize=10)

    # draw baseline=1
    ax2.axhline(y=1, color='gray', linestyle='--', linewidth=2)

    ax2.grid(True, axis='y', color="gray", linestyle='--', linewidth=0.5, alpha=0.5)
    ax2.set_ylabel("proportion", fontsize=15)

    # ax2.legend(fontsize=15)
    plt.savefig(f"./wasi_{mode}{runtime}.pdf", bbox_inches='tight', format='pdf')
    plt.clf()

def draw_result_nativewasm(mode="simple", runtime=""):

    if runtime:
        runtime = f"_{runtime}"
    
    # 1. draw a figure that has two-y-axis
    # ax1 is the bar of execution time of each image
    # ax2 is the plot the relative speedup of each image

    with open(f"results{runtime}.json", "r") as f:
        result = json.load(f)
    x_label = ['read', 'write', 'delete']
    x = [ "read", "create", "delete"]

    x_loc = [i for i in range(len(x))]
    
    native_execution = [result[i]['native_wasm']['execution'] for i in x]
    wasm_execution = [result[i]['wasm']['execution'] for i in x]

    speed_up = [wasm_execution[i]/native_execution[i] for i in range(len(x))]
    print(speed_up)
    absolute = [wasm_execution[i] - native_execution[i] for i in range(len(x))]
    print(absolute)

    WIDTH = 0.2

    plt.figure(figsize=(8, 4))
    plt.bar([i - WIDTH for i in x_loc], native_execution, width=2*WIDTH, label="native wasm", color="black")
    # draw a line to separate native and wasm
    plt.bar([i + WIDTH for i in x_loc], wasm_execution, width=2*WIDTH, label="wasm container", edgecolor="black", color="white", hatch='//')

    plt.xticks(x_loc, x_label, fontsize=15)
    plt.yticks(fontsize=15)
    plt.ylabel("time(ms)", fontsize=15)
    # plt.xlabel("benchmarks", fontsize=15)
    # plt.grid(True, axis='x', color="white")

    plt.legend(fontsize=15)
    # plt.savefig(f"./time_absolute_nativewasm{runtime}.png", bbox_inches='tight')
    # plt.clf()

    # draw relative
    ax2 = plt.twinx()    
    ax2.plot(x_loc, [wasm_execution[i]/native_execution[i] for i in range(len(x))], label="execution", marker='*', color='orange', linewidth=2, markersize=10)

    # draw baseline=1
    ax2.axhline(y=1, color='gray', linestyle='--', linewidth=2)

    ax2.grid(True, axis='y', color="gray", linestyle='--', linewidth=0.5, alpha=0.5)
    ax2.set_ylabel("proportion", fontsize=15)

    # ax2.legend(fontsize=15)
    plt.savefig(f"./wasi_{mode}_nativewasm{runtime}.pdf", bbox_inches='tight', format='pdf')
    plt.clf()


if __name__ == "__main__":
    runtimes = ["wasmtime", "wasmer", "wasmedge"]
    for r in runtimes:
        get_results(r)
        draw_results("file", r)

        draw_result_nativewasm("file", r)