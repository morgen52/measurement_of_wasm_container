import docker
import json
from tqdm import tqdm
import os
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np

from utils.configs import docker_url

client = docker.DockerClient(base_url=docker_url)

COMPILE_DIR = "../compiled"
LOG_DIR = "measured_results"
FIG_DIR = "figures"

def get_storage():
    funcs = sorted(os.listdir(COMPILE_DIR))

    # check the images size of images in data
    logfile = f"{LOG_DIR}/storage.json"
    if os.path.exists(logfile):
        with open(logfile, 'r', encoding='utf-8') as f:
            sizes = json.load(f)

    sizes = {}

    for func in tqdm(funcs):
        if func in sizes.keys():
            continue
        try:
            sizes[func] = {
                "wasm": client.images.get(f"wasmbench/{func}:0.1").attrs["Size"] / 1024, # KiB
                "native": client.images.get(f"wasmbench/{func}:0.0").attrs["Size"] / 1024 # KiB
            }
        except:
            print(f"Error: {func}")
            continue

        with open(logfile, 'w', encoding='utf-8') as f:
            json.dump(sizes, f, indent=2)

def draw():
    logfile = f"{LOG_DIR}/storage.json"

    with open(logfile, 'r', encoding='utf-8') as f:
        sizes = json.load(f)
    
    FONTSIZE = 15

    wasm_sizes = []
    native_sizes = []
    for i in sizes.values():
        wasm_sizes.append(i["wasm"])
        native_sizes.append(i["native"])

    plt.figure(figsize=(9, 3))
    plt.scatter(wasm_sizes, [kb / 1024 for kb in native_sizes], color="white", edgecolors="black")
    plt.xlabel("wasm image size (KiB)", fontsize=FONTSIZE)
    plt.ylabel("linux image size (MiB)", fontsize=FONTSIZE)
    plt.xticks(fontsize=FONTSIZE)
    plt.yticks(fontsize=FONTSIZE)

    plt.gca().xaxis.set_major_formatter(ticker.FormatStrFormatter('%.2f'))
    plt.gca().yaxis.set_major_formatter(ticker.FormatStrFormatter('%.2f'))
    plt.grid(True, axis='both', linestyle='--', linewidth=0.5, color='gray', alpha=0.5)
    plt.savefig(f"{FIG_DIR}/size_scatter.pdf", dpi=300, bbox_inches='tight', format='pdf')
    plt.clf()

if __name__ == "__main__":
    get_storage()
    draw()






    