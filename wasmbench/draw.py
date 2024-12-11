import json
import matplotlib.pyplot as plt

LOG_DIR = "measured_results"
FIG_DIR = "figures"

def draw():
    wasmtime_file = f"{LOG_DIR}/results.json.wasmtime"
    wasmer_file = f"{LOG_DIR}/results.json.wasmer"
    with open(wasmtime_file, "r") as f1,\
        open(wasmer_file, "r") as f2:
        results = json.load(f1)
        wasmer_results = json.load(f2)
    
    print(f"Total {len(results.keys())} wasmtime files.")
    print(f"Total {len(wasmer_results.keys())} wasmer files.")

    FONTSIZE = 15
    
    startup_wasm = [results[code]["wasm"]["startup"] for code in results.keys()]
    startup_wasm_container = [results[code]["wasm_container"]["startup"] for code in results.keys()]
    startup_linux_container = [results[code]["linux_container"]["startup"] for code in results.keys()]
    startup_wasmer = [wasmer_results[code]["wasm"]["startup"] for code in wasmer_results.keys()]
    startup_wasmer_container = [wasmer_results[code]["wasm_container"]["startup"] for code in wasmer_results.keys()]

    startup_wasm = sorted(startup_wasm)
    startup_wasm_container = sorted(startup_wasm_container)
    startup_linux_container = sorted(startup_linux_container)
    startup_wasmer = sorted(startup_wasmer)
    startup_wasmer_container = sorted(startup_wasmer_container)

    plt.figure(figsize=(9, 3))
    plt.plot(startup_linux_container, [i / len(startup_linux_container) for i in range(len(startup_linux_container))], label="docker container", color="black", linewidth=2, linestyle="-")
    plt.plot(startup_wasm, [i / len(startup_wasm) for i in range(len(startup_wasm))], label="wasmtime", color="#FFA500", linewidth=2, linestyle="-.")
    plt.plot(startup_wasm_container, [i / len(startup_wasm_container) for i in range(len(startup_wasm_container))], label="wasmtime container", color="#FFA500", linewidth=2, linestyle="--")
    plt.plot(startup_wasmer, [i / len(startup_wasmer) for i in range(len(startup_wasmer))], label="wasmer", color="#DC2F2F", linewidth=2, linestyle="--", marker=".", markevery=50, markersize=8)
    plt.plot(startup_wasmer_container, [i / len(startup_wasmer_container) for i in range(len(startup_wasmer_container))], label="wasmer container", color="#DC2F2F", linewidth=2, linestyle=":")

    plt.legend(fontsize=FONTSIZE, loc="upper center", bbox_to_anchor=(0.4, 1), ncol=1)
    plt.xlabel("startup time (ms)", fontsize=FONTSIZE)
    plt.ylabel("cdf", fontsize=FONTSIZE)
    plt.xticks(fontsize=FONTSIZE)
    plt.yticks(fontsize=FONTSIZE)
    plt.grid(True, axis="both", linestyle="--", color="gray",linewidth=0.5, alpha=0.5)
    # plt.savefig(f"{FIG_DIR}/wasmbench_startup_all.pdf", bbox_inches='tight', format="pdf")
    plt.savefig(f"{FIG_DIR}/wasmbench_startup_all.png", bbox_inches='tight', dpi=300)
    plt.clf()

    e2e_wasm = [results[code]["wasm"]["e2e"] for code in results.keys()]
    e2e_wasm_container = [results[code]["wasm_container"]["e2e"] for code in results.keys()]
    e2e_linux_container = [results[code]["linux_container"]["e2e"] for code in results.keys()]
    e2e_wasmer = [wasmer_results[code]["wasm"]["e2e"] for code in wasmer_results.keys()]
    e2e_wasmer_container = [wasmer_results[code]["wasm_container"]["e2e"] for code in wasmer_results.keys()]

    e2e_wasm = sorted(e2e_wasm)
    e2e_wasm_container = sorted(e2e_wasm_container)
    e2e_linux_container = sorted(e2e_linux_container)
    e2e_wasmer = sorted(e2e_wasmer)
    e2e_wasmer_container = sorted(e2e_wasmer_container)

    plt.figure(figsize=(9, 3))
    plt.plot(e2e_linux_container, [i / len(e2e_linux_container) for i in range(len(e2e_linux_container))], label="docker container", color="black", linewidth=2, linestyle="-")
    plt.plot(e2e_wasm, [i / len(e2e_wasm) for i in range(len(e2e_wasm))], label="wasmtime", color="#FFA500", linewidth=2, linestyle="-.")
    plt.plot(e2e_wasm_container, [i / len(e2e_wasm_container) for i in range(len(e2e_wasm_container))], label="wasmtime container", color="#FFA500", linewidth=2, linestyle="--")
    plt.plot(e2e_wasmer, [i / len(e2e_wasmer) for i in range(len(e2e_wasmer))], label="wasmer", color="#DC2F2F", linewidth=2, linestyle="--", marker=".", markevery=50, markersize=8)
    plt.plot(e2e_wasmer_container, [i / len(e2e_wasmer_container) for i in range(len(e2e_wasmer_container))], label="wasmer container", color="#DC2F2F", linewidth=2, linestyle=":")

    plt.legend(fontsize=FONTSIZE, loc="upper center", bbox_to_anchor=(0.4, 1), ncol=1)
    plt.xlabel("e2e time (ms)", fontsize=FONTSIZE)
    plt.ylabel("cdf", fontsize=FONTSIZE)
    plt.xticks(fontsize=FONTSIZE)
    plt.yticks(fontsize=FONTSIZE)
    plt.grid(True, axis="both", linestyle="--", color="gray",linewidth=0.5, alpha=0.5)
    # plt.savefig(f"{FIG_DIR}/wasmbench_e2e_all.pdf", bbox_inches='tight', format="pdf")    
    plt.savefig(f"{FIG_DIR}/wasmbench_e2e_all.png", bbox_inches='tight', dpi=300) 

if __name__ == "__main__":
    draw()