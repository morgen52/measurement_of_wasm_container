import os
from tqdm import tqdm

from utils.benchmarks import get_configs
from utils.configs import specific_compile_cmd

def build_wasm(f):
    current_dir = os.getcwd()

    version = "0.1"
    fname = f['result'].split("/")[-1]
    src_dir = "source_code"
    os.chdir(src_dir)
    target_dir = "../" + "/".join(f['result'].split("/")[:-1])

    os.makedirs(target_dir, exist_ok=True)

    # emcc compile to wasm
    if f['src'] in specific_compile_cmd.keys():
        cmd = specific_compile_cmd[f['src']]['wasm']
    else:
        cmd = f"emcc -O3 -s WASM=1 -s TOTAL_MEMORY=75497472 -I utilities -I {f['depends']} utilities/polybench.c {f['src']} -DPOLYBENCH_TIME -DNDEBUG -o ../{f['result']}.wasm"
    
    os.system(cmd)
    # build container
    with open(f"{target_dir}/Dockerfile_wasm", "w") as df:
        lines = [
            f"FROM scratch\n",
            f"COPY ./{fname}.wasm /{fname}.wasm\n",
            f'CMD ["/{fname}.wasm"]\n'
        ]
        df.writelines(lines)

    os.chdir(target_dir)
    # --provenance=false: disable the provenance feature for smaller image size
    cmd = f"docker buildx build -f ./Dockerfile_wasm --platform wasi/wasm --provenance=false -t liminfinity/{fname}:{version} . "
    print(cmd)
    os.system(cmd)

    os.chdir(current_dir)

def build_native(f):
    current_dir = os.getcwd()

    version = "0.0"
    fname = f['result'].split("/")[-1]

    src_dir = "source_code"
    os.chdir(src_dir)
    target_dir = "../" + "/".join(f['result'].split("/")[:-1])
    os.makedirs(target_dir, exist_ok=True)

    # gcc compile to native
    cmd = ""
    if f['src'] in specific_compile_cmd.keys():
        cmd = specific_compile_cmd[f['src']]['gcc']
    else:
        cmd = f"gcc -O3 -I utilities -I {f['depends']} utilities/polybench.c {f['src']} -DPOLYBENCH_TIME -o ../{f['result']} -lm"

    print(cmd)
    os.system(cmd)

    with open(f"{target_dir}/Dockerfile_native", "w") as df,\
        open(f"../Dockerfile.template", "r") as tf:
        lines = tf.readlines()
        for idx, line in enumerate(lines):
            lines[idx] = line.replace("COMPILE", cmd.replace("../compiled/", "")).replace("RESULT", f['result'].replace("compiled/", "")).replace("FNAME", fname)
        df.writelines(lines)

    # build docker image
    cmd = f"docker buildx build -f {target_dir}/Dockerfile_native --provenance=false --platform linux/amd64 -t liminfinity/{fname}:{version} . "
    print(cmd)
    os.system(cmd)

    os.chdir(current_dir)

def build_docker_containers(flst):
    # compile and build containers for both native and wasm
    for f in tqdm(flst):
        build_native(f)
        build_wasm(f)

if __name__ == "__main__":
    flst = get_configs()
    build_docker_containers(flst)


    