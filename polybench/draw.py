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
    plt.savefig(f"{FIG_DIR}/time_startup_absolute_all.pdf", bbox_inches='tight', format='pdf')
    plt.clf()

    # plt.figure(figsize=(9, 3))
    # plt.plot(x, [wasm_startup[i]/native_startup[i] for i in range(len(x))], label="startup (wasmtime)", marker='o', color='black', linewidth=2)
    # plt.plot(x, [wasm_compute[i]/native_compute[i] for i in range(len(x))], label="compute (wasmtime)", marker='*', color='black', linewidth=2)
    # # draw baseline=1
    # plt.axhline(y=1, linestyle='--', color='grey', label="docker")
    # plt.plot(x, [wasmer_startup[i]/native_startup[i] for i in range(len(x))], label="startup (wasmer)", marker='o', color='#929AAB', linewidth=2, linestyle="--")
    # plt.plot(x, [wasmer_compute[i]/native_compute[i] for i in range(len(x))], label="compute (wasmer)", marker='*', color='#929AAB', linewidth=2, linestyle="--")

    # plt.xticks(x, rotation=90, fontsize=12)
    # plt.yticks(fontsize=15)
    # plt.ylabel("ratio (wasm / docker)", fontsize=15)
    # plt.xlabel("benchmarks", fontsize=15)
    # plt.grid(True, axis='both', linestyle='--', linewidth=0.5, color="gray", alpha=0.5)

    # plt.legend(fontsize=15, ncol=2)
    # plt.savefig(f"{FIG_DIR}/poly_compute_all.pdf", bbox_inches='tight', format='pdf')
    # plt.clf()

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
    ax1.set_xlabel("benchmarks", fontsize=15)
    ax1.set_xticks(x_loc)
    ax1.set_xticklabels(x, rotation=90, fontsize=12)
    ax1.tick_params(axis='y', labelsize=15)
    ax1.set_xlim(min(x_loc) - 0.6, max(x_loc) + 0.6)
    # ax1.set_ylim(0, 350)

    # ax1.legend(fontsize=12, loc='upper center', ncol=2, bbox_to_anchor=(0.5, 1.25))
    handles, labels = ax1.get_legend_handles_labels()
    sorted_labels = ["startup (wasmtime)", "compute (wasmtime)", "startup (wasmer)", "compute (wasmer)", "docker"]
    sorted_handles = [handles[labels.index(label)] for label in sorted_labels]

    # Create the sorted legend
    ax1.legend(sorted_handles, sorted_labels, fontsize=12, ncol=3, loc='upper center')


    plt.grid(True, axis='both', linestyle='--', linewidth=0.5, color="gray", alpha=0.5)
    plt.savefig(f"{FIG_DIR}/poly_compute_all.pdf", bbox_inches='tight', format='pdf')
    plt.clf()




if __name__ == "__main__":
    draw_all_runtime()
    