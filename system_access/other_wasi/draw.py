import json
import matplotlib.pyplot as plt

LOG_DIR = 'measured_results'
FIG_DIR = 'figures'

def get_results(runtime):
    with open(f"{LOG_DIR}/results_{runtime}.json", "r") as f:
        result = json.load(f)
    x_label = ['stdout', 'time', 'rand']
    x = ["liminfinity/stdout_wasi", "liminfinity/time_wasi", "liminfinity/rand_wasi"]
    return result, x_label, x

def draw_results(runtime="wasmer"):    
    result, x_label, x = get_results(runtime)

    x_loc = [i for i in range(len(x))]
    
    native_execution = [result[i]['native']['execution'] for i in x]
    wasm_execution = [result[i]['wasm']['execution'] for i in x]
    nativewasm_execution = [result[i]['native_wasm']['execution'] for i in x]

    WIDTH = 0.2
    plt.figure(figsize=(8, 4))
    plt.bar([i - WIDTH for i in x_loc], native_execution, width=WIDTH, label="linux container", color="black")
    plt.bar([i for i in x_loc], wasm_execution, width=WIDTH, label="wasm container", color="white", edgecolor="black", hatch="//")
    plt.bar([i + WIDTH for i in x_loc], nativewasm_execution, width=WIDTH, label="native wasm", color="white", edgecolor="black", hatch="\\")

    # add value on the top of the bar
    for i, v in enumerate(native_execution):
        plt.text(i - WIDTH, v + 0.1, f"{v:.2f}", ha='center', va='bottom')
    for i, v in enumerate(wasm_execution):
        plt.text(i, v + 0.1, f"{v:.2f}", ha='center', va='bottom')
    for i, v in enumerate(nativewasm_execution):
        plt.text(i + WIDTH, v + 0.1, f"{v:.2f}", ha='center', va='bottom')

    plt.xticks(x_loc, x_label, fontsize=15)
    plt.yticks(fontsize=15)
    plt.ylabel("time(ms)", fontsize=15)

    plt.legend(fontsize=15)

    plt.savefig(f"{FIG_DIR}/wasi_{runtime}.pdf", bbox_inches='tight', format='pdf')
    plt.clf()

if __name__ == '__main__':
    runtimes = ["wasmtime", "wasmer"]
    for r in runtimes:
        draw_results(r)
