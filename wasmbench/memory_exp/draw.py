import json
import matplotlib.pyplot as plt
import numpy as np

LOG_DIR = "measured_results"
FIG_DIR = "figures"

def draw():
    with open(f"{LOG_DIR}/results_wasmvm.json.wasmtime", 'r', encoding='utf-8') as f1,\
        open(f"{LOG_DIR}/results.json.wasmtime", 'r', encoding='utf-8') as f2:
        results_nativewasm = json.load(f1)
        results = json.load(f2)
    
    results_nativewasm = {k: v for k, v in results_nativewasm.items() if k in results}

    wasm_memory_usage = [item["wasm"]["execute"]["memory"] for item in results.values()]
    native_memory_usage = [item["native"]["execute"]["memory"] for item in results.values()]
    nativewasm_memory_usage = [item["native_wasm"]["execute"]["memory"] for item in results_nativewasm.values()]

    base_wasm_memory_usage = min([item["wasm"]["before"]["memory"] for item in results.values()])
    base_native_memory_usage = min([item["native"]["before"]["memory"] for item in results.values()])
    base_nativewasm_memory_usage = min([item["native_wasm"]["before"]["memory"] for item in results_nativewasm.values()])
    
    wasm_memory_usage_overhead = [item - base_wasm_memory_usage for item in wasm_memory_usage]
    native_memory_usage_overhead = [item - base_native_memory_usage for item in native_memory_usage]
    nativewasm_memory_usage_overhead = [item - base_nativewasm_memory_usage for item in nativewasm_memory_usage]

    FONTSIZE = 15
    
    plt.figure(figsize=(9, 3))
    plt.plot(sorted(native_memory_usage_overhead), np.linspace(0, 1, len(native_memory_usage_overhead)), label="docker container", color='black', linewidth=2, linestyle='-')
    plt.plot(sorted(wasm_memory_usage_overhead), np.linspace(0, 1, len(wasm_memory_usage_overhead)), label="wasmtime container", color='#DC2F2F', linewidth=2, linestyle='--')
    plt.plot(sorted(nativewasm_memory_usage_overhead), np.linspace(0, 1, len(nativewasm_memory_usage_overhead)), label="wasmtime", color='gray', linewidth=2, linestyle='-.')

    plt.xlabel("memory overhead (MiB)", fontsize=FONTSIZE)
    plt.ylabel("cdf", fontsize=FONTSIZE)
    plt.xticks(fontsize=FONTSIZE)
    plt.yticks(fontsize=FONTSIZE)
    plt.legend(fontsize=FONTSIZE)
    plt.grid(True, axis='both', linestyle='--', linewidth=0.5, alpha=0.5, color='gray')
    # plt.savefig(f"{FIG_DIR}/memory_usage_overhead_cdf_nw_wasmtime.pdf", dpi=300, bbox_inches='tight', format='pdf')
    plt.savefig(f"{FIG_DIR}/memory_usage_overhead_cdf_nw_wasmtime.png", dpi=300, bbox_inches='tight')
    plt.clf()

if __name__ == "__main__":
    draw()


