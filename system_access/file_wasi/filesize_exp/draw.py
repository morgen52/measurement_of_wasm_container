import json
import matplotlib.pyplot as plt
import math

LOG_DIR = 'measured_results'
FIG_DIR = 'figures'

def draw_result(read, write, runtime):
    with open(f"{LOG_DIR}/wasm_container_{runtime}.json", "r") as f1,\
        open(f"{LOG_DIR}/native_container.json", "r") as f2, \
        open(f"{LOG_DIR}/wasm_vm_{runtime}.json", "r") as f3,\
        open(f"{LOG_DIR}/native.json", "r") as f4:
        wasm = json.load(f1)
        native = json.load(f2)
        native_wasm = json.load(f3)
        native_native = json.load(f4)
    
    x = [str(i) for i in range(0, len(wasm.keys()))]
    wasm_read = [math.log(wasm[key]["read file"]/1000, 2) for key in wasm.keys()]
    wasm_write = [math.log(wasm[key]["create file"]/1000, 2) for key in wasm.keys()]

    native_read = [math.log(native[key]["read file"]/1000, 2) for key in native.keys()]
    native_write = [math.log(native[key]["create file"]/1000, 2) for key in native.keys()]

    native_wasm_read = [math.log(native_wasm[key]["read file"]/1000, 2) for key in native_wasm.keys()]
    native_wasm_write = [math.log(native_wasm[key]["create file"]/1000, 2) for key in native_wasm.keys()]

    native_native_read = [math.log(native_native[key]["read file"]/1000, 2) for key in native_native.keys()]
    native_native_write = [math.log(native_native[key]["create file"]/1000, 2) for key in native_native.keys()]

    plt.figure(figsize=(9, 3))
    if read == 1:
        plt.plot(x, wasm_read, label="wasm_container_read", marker='o', color='black', linewidth=2, linestyle='-')
        plt.plot(x, native_read, label="docker_container_read", marker='*', color='#B0A4A4', linewidth=2, linestyle='-', markersize=8)
        plt.plot(x, native_wasm_read, label="wasm_vm_read", color='blue', linewidth=2, linestyle='--')
        plt.plot(x, native_native_read, label="native_binary_read", color='red', linewidth=2, linestyle=':')
        plt.axvline(x=15, linestyle='--', color='grey', linewidth=2)
    if write == 1:
        plt.plot(x, wasm_write, label="wasm_container_write", marker='o', color='black', linewidth=2, linestyle='-')
        plt.plot(x, native_write, label="docker_container_write", marker='*', color='#B0A4A4', linewidth=2, linestyle='-', markersize=8)
        plt.plot(x, native_wasm_write, label="wasm_vm_write", color='blue', linewidth=2, linestyle='--')
        plt.plot(x, native_native_write, label="native_binary_write", color='red', linewidth=2, linestyle=':')
        plt.axvline(x=15, linestyle='--', color='grey', linewidth=2)

    xsticks = [f"2^{i}" for i in x]
    plt.xticks(x[::5], xsticks[::5], fontsize=15)
    plt.xlabel("file size (byte)", fontsize=15)

    plt.yticks(fontsize=15)
    # plt.ylabel("time 2^Y (microsecond)", fontsize=15)
    plt.ylabel("time 2^Y (μs)", fontsize=15)

    plt.legend(fontsize=15)  
    plt.grid(True, axis='both', color="gray", linestyle='--', linewidth=0.5, alpha=0.5)

    # plt.savefig(f"{FIG_DIR}/filesize_{'read' if read else 'write'}_{runtime}.pdf", bbox_inches='tight', format='pdf')
    plt.savefig(f"{FIG_DIR}/filesize_{'read' if read else 'write'}_{runtime}.png", bbox_inches='tight', dpi=300)
    plt.clf()

def results_analysis():
    runtime = "wasmer"
    with open(f"{LOG_DIR}/wasm_container_{runtime}.json", "r") as f1,\
        open(f"{LOG_DIR}/native_container.json", "r") as f2, \
        open(f"{LOG_DIR}/wasm_vm_{runtime}.json", "r") as f3,\
        open(f"{LOG_DIR}/native.json", "r") as f4:
        wasm = json.load(f1)
        native = json.load(f2)
        native_wasm = json.load(f3)
        native_native = json.load(f4)
    
    wasm_read = [math.log(wasm[key]["read file"]/1000, 2) for key in wasm.keys()]
    native_read = [math.log(native[key]["read file"]/1000, 2) for key in native.keys()]
    native_wasm_read = [math.log(native_wasm[key]["read file"]/1000, 2) for key in native_wasm.keys()]
    native_native_read = [math.log(native_native[key]["read file"]/1000, 2) for key in native_native.keys()]

    # below 15, Wasm containers take an average ?? times longer than Linux containers
    average = sum([math.pow(2, wasm_read[i]) / math.pow(2, native_read[i]) for i in range(0, 15)]) / 15
    std = math.sqrt(sum([math.pow(math.pow(2, wasm_read[i]) / math.pow(2, native_read[i]) - average, 2) for i in range(0, 15)]) / 15)
    print(f"below 15, {runtime} containers take an average {average:.1f} (+/- {std:.1f}) times longer than Linux containers")

    # below a threshold size, Wasm/Linux containers take around ?? longer than Wasm/native binaries.
    average = sum([math.pow(2, wasm_read[i]) / math.pow(2, native_wasm_read[i]) for i in range(0, 15)]) / 15
    std = math.sqrt(sum([math.pow(math.pow(2, wasm_read[i]) / math.pow(2, native_wasm_read[i]) - average, 2) for i in range(0, 15)]) / 15)
    print(f"below 15, {runtime} containers take an average {average:.2f} (+/- {std:.2f}) times longer than Wasm binaries")
    average = sum([math.pow(2, native_read[i]) / math.pow(2, native_native_read[i]) for i in range(0, 15)]) / 15
    std = math.sqrt(sum([math.pow(math.pow(2, native_read[i]) / math.pow(2, native_native_read[i]) - average, 2) for i in range(0, 15)]) / 15)
    print(f"below 15, Linux containers take an average {average:.2f} (+/- {std:.2f}) times longer than native binaries")


if __name__ == "__main__":
    runtimes = ["wasmer"]

    for r in runtimes:
        draw_result(read=1, write=0, runtime=r)
    
    results_analysis()
