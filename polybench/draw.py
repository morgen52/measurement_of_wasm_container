import json
import matplotlib.pyplot as plt

def draw_all_runtime():
    LOG_DIR = "measured_results"
    FIG_DIR = "figures"
    wasmtime_file = f"{LOG_DIR}/docker_time_result.json.wasmtime"
    wasmer_file = f"{LOG_DIR}/docker_time_result.json.wasmer"

    with open(wasmtime_file, "r", encoding="utf8") as f1,\
        open(wasmer_file, "r", encoding="utf8") as f2:
        wasmtime_result = json.load(f1)
        wasmer_result = json.load(f2)

    x_loc = [i for i in range(len(wasmtime_result.keys()))]
    x = [i for i in range(1, len(wasmtime_result.keys())+1)]
    native_startup = [wasmtime_result[k]['native']['startup'] for k in wasmtime_result.keys()]
    native_compute = [wasmtime_result[k]['native']['compute'] for k in wasmtime_result.keys()]
    wasm_startup = [wasmtime_result[k]['wasm']['startup'] for k in wasmtime_result.keys()]
    wasm_compute = [wasmtime_result[k]['wasm']['compute'] for k in wasmtime_result.keys()]

    wasmer_startup = [wasmer_result[k]['wasm']['startup'] for k in wasmer_result.keys()]
    wasmer_compute = [wasmer_result[k]['wasm']['compute'] for k in wasmer_result.keys()]

    WIDTH = 0.2
    fig = plt.figure(figsize=(9, 3))
    ax1 = fig.add_subplot(111)
    l1 = ax1.bar([i - 1.5*WIDTH for i in x_loc], native_startup, width=1.5*WIDTH, label="docker container", color="black")
    l2 = ax1.bar([i for i in x_loc], wasm_startup, width=1.5*WIDTH, label="wasmtime container", edgecolor="black", color="white")
    l3 = ax1.bar([i + 1.5*WIDTH for i in x_loc], wasmer_startup, width=1.5*WIDTH, label="wasmer container", edgecolor="black", color="white", hatch="//")

    ax1.set_ylabel("time(ms)", fontsize=15)
    ax1.set_xlabel("benchmarks", fontsize=15)
    ax1.set_xticks(x_loc)
    ax1.set_xticklabels(x, rotation=90, fontsize=12)
    ax1.tick_params(axis='y', labelsize=15)
    ax1.set_xlim(min(x_loc) - 0.6, max(x_loc) + 0.6)
    # ax1.set_ylim(0, 350)

    ax1.legend(fontsize=12, loc='upper center', ncol=3, bbox_to_anchor=(0.5, 1.2))

    plt.grid(True, axis='both', linestyle='--', linewidth=0.5, color="gray", alpha=0.5)
    # plt.savefig(f"{FIG_DIR}/time_startup_absolute_all.pdf", bbox_inches='tight', format='pdf')
    plt.savefig(f"{FIG_DIR}/time_startup_absolute_all.png", bbox_inches='tight', dpi=300)
    plt.clf()

    memIntensive = [1,2,22,23,24,26,27]
    cpuIntensive = [3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,25,28,29,30]
    x = [f"{xi}#" if xi in memIntensive else f"{xi}*" for xi in x]

    plt.figure(figsize=(12, 3))
    wasm_startup_ratio = [wasm_startup[i]/native_startup[i] for i in range(len(x))]
    wasm_compute_ratio = [wasm_compute[i]/native_compute[i] for i in range(len(x))]
    wasmer_startup_ratio = [wasmer_startup[i]/native_startup[i] for i in range(len(x))]
    wasmer_compute_ratio = [wasmer_compute[i]/native_compute[i] for i in range(len(x))]

    WIDTH = 0.2
    ax1 = plt.subplot(111)
    l1 = ax1.bar([i - 1.5*WIDTH for i in x_loc], wasm_startup_ratio, width=WIDTH, label="startup (wasmtime)", color="grey", edgecolor="black", hatch="//")
    l2 = ax1.bar([i - 0.5*WIDTH for i in x_loc], wasm_compute_ratio, width=WIDTH, label="compute (wasmtime)", color="grey", edgecolor="black")
    l3 = ax1.bar([i + 0.5*WIDTH for i in x_loc], wasmer_startup_ratio, width=WIDTH, label="startup (wasmer)", color="white", edgecolor="black", hatch="//")
    l4 = ax1.bar([i + 1.5*WIDTH for i in x_loc], wasmer_compute_ratio, width=WIDTH, label="compute (wasmer)", color="white", edgecolor="black")

    # Draw baseline at 1
    ax1.axhline(y=1, linestyle='--', color='grey', label="docker", linewidth=1.5)

    ax1.set_ylabel("ratio (wasm / docker)", fontsize=15)
    ax1.set_xlabel("benchmarks (#: memory-intensive; *:compute-intensive)", fontsize=15)
    ax1.set_xticks(x_loc)
    ax1.set_xticklabels(x, rotation=90, fontsize=12)
    ax1.tick_params(axis='y', labelsize=15)
    ax1.set_yticks([0, 1, 2, 3, 4, 5])
    ax1.set_xlim(min(x_loc) - 0.6, max(x_loc) + 0.6)
    # ax1.set_ylim(0, 350)

    # ax1.legend(fontsize=12, loc='upper center', ncol=2, bbox_to_anchor=(0.5, 1.25))
    handles, labels = ax1.get_legend_handles_labels()
    sorted_labels = ["startup (wasmtime)", "compute (wasmtime)", "startup (wasmer)", "compute (wasmer)", "docker"]
    sorted_handles = [handles[labels.index(label)] for label in sorted_labels]

    # Create the sorted legend
    ax1.legend(sorted_handles, sorted_labels, fontsize=12, ncol=3, loc='upper center')


    plt.grid(True, axis='both', linestyle='--', linewidth=0.5, color="gray", alpha=0.5)
    # plt.savefig(f"{FIG_DIR}/poly_compute_all.pdf", bbox_inches='tight', format='pdf')
    plt.savefig(f"{FIG_DIR}/poly_compute_all.png", bbox_inches="tight", dpi=300)
    plt.clf()

def results_analysis():
    LOG_DIR = "measured_results"
    wasmtime_file = f"{LOG_DIR}/docker_time_result.json.wasmtime"
    wasmer_file = f"{LOG_DIR}/docker_time_result.json.wasmer"

    with open(wasmtime_file, "r", encoding="utf8") as f1,\
        open(wasmer_file, "r", encoding="utf8") as f2:
        wasmtime_result = json.load(f1)
        wasmer_result = json.load(f2)

    native_startup = [wasmtime_result[k]['native']['startup'] for k in wasmtime_result.keys()]
    native_compute = [wasmtime_result[k]['native']['compute'] for k in wasmtime_result.keys()]
    wasm_startup = [wasmtime_result[k]['wasm']['startup'] for k in wasmtime_result.keys()]
    wasm_compute = [wasmtime_result[k]['wasm']['compute'] for k in wasmtime_result.keys()]

    wasmer_startup = [wasmer_result[k]['wasm']['startup'] for k in wasmer_result.keys()]
    wasmer_compute = [wasmer_result[k]['wasm']['compute'] for k in wasmer_result.keys()]

    # how much slower is the startup time of wasmtime compared to native? Average and standard deviation
    startup_ratio = [wasm_startup[i]/native_startup[i] for i in range(len(native_startup))]
    average_startup_ratio = sum(startup_ratio) / len(startup_ratio)
    std_startup_ratio = (sum([(r - average_startup_ratio)**2 for r in startup_ratio]) / len(startup_ratio))**0.5
    print(f"Average startup ratio (wasmtime/native): {average_startup_ratio:.2f} +- {std_startup_ratio:.2f}")

    # median number of compute time slowdown of wasmtime and wasmer compared to native
    compute_ratio = [wasm_compute[i]/native_compute[i] for i in range(len(native_compute))]
    compute_ratio_wasmer = [wasmer_compute[i]/native_compute[i] for i in range(len(native_compute))]
    compute_ratio.sort()
    compute_ratio_wasmer.sort()
    median_compute_ratio = sum(compute_ratio[14:16]) / 2
    median_compute_ratio_wasmer = sum(compute_ratio_wasmer[14:16]) / 2
    print(f"Median compute ratio (wasmtime/native): {median_compute_ratio:.2f}, (wasmer/native): {median_compute_ratio_wasmer:.2f}")

    # how many benchmarks compute faster in wasmer and wasmtime than in native, and what is their names
    faster_compute = [1 if wasm_compute[i] < native_compute[i] else 0 for i in range(len(native_compute))]
    faster_compute_wasmer = [1 if wasmer_compute[i] < native_compute[i] else 0 for i in range(len(native_compute))]
    benchmarks = list(wasmtime_result.keys())
    print(f"Number of benchmarks compute faster in wasmtime: {sum(faster_compute)}")
    for i, b in enumerate(benchmarks):
        if faster_compute[i]:
            print(f"{i+1}({b})", end=" ")
    print(f"\nNumber of benchmarks compute faster in wasmer: {sum(faster_compute_wasmer)}")

if __name__ == "__main__":
    draw_all_runtime()
    # results_analysis()
    