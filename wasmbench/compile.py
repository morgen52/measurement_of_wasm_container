import os
from tqdm import tqdm

SRC_DIR = "source_code"
COMPILE_DIR = "compiled"
CURRENT_DIR = os.getcwd()

def compile():
    for file in tqdm(os.listdir(SRC_DIR)):
        assert file.endswith(".c") or file.endswith(".cpp") or file.endswith(".cc")

        name = ".".join(file.split(".")[:-1])
        if not os.path.exists(f"{COMPILE_DIR}/{name}"):
            os.makedirs(f"{COMPILE_DIR}/{name}")

        if file.endswith(".c"):
            os.system(f"gcc -O3 -o {COMPILE_DIR}/{name}/{name} {SRC_DIR}/{file} -lm")
            os.system(f"emcc -O3 -o {COMPILE_DIR}/{name}/{name}.wasm {SRC_DIR}/{file} -lm")
        elif file.endswith(".cpp") or file.endswith(".cc"):
            os.system(f"g++ -O3 -o {COMPILE_DIR}/{name}/{name} {SRC_DIR}/{file} -lm")
            os.system(f"em++ -O3 -o {COMPILE_DIR}/{name}/{name}.wasm {SRC_DIR}/{file} -lm")

def gen_docker_file():
    temp_linux = []
    temp_wasm = []
    with open("./Dockerfile.Linux.template", "r") as f1,\
        open("./Dockerfile.Wasm.template", "r") as f2:
        temp_linux = f1.readlines()
        temp_wasm = f2.readlines()

    print("Generating Dockerfile for each source code file...")

    for file in tqdm(os.listdir(SRC_DIR)):
        if not (file.endswith(".c") or file.endswith(".cpp") or file.endswith(".cc")):
            continue

        tmp_linux = temp_linux.copy()
        name = file.split(".")[0]

        for idx in range(len(tmp_linux)):
            tmp_linux[idx] = tmp_linux[idx].replace("SRC", file)
            if file.endswith(".c"):
                tmp_linux[idx] = tmp_linux[idx].replace("COMPILE",\
                                                    f"gcc -O3 -o ./{name} ./{file} -lm")
            elif file.endswith(".cpp") or file.endswith(".cc"):
                tmp_linux[idx] = tmp_linux[idx].replace("COMPILE",\
                                                    f"g++ -O3 -o ./{name} ./{file} -lm")
            tmp_linux[idx] = tmp_linux[idx].replace("FNAME", name)

        with open(f"{COMPILE_DIR}/{name}/Dockerfile_native", "w") as f:
            f.writelines(tmp_linux)
        
        tmp_wasm = temp_wasm.copy()
        for idx in range(len(tmp_wasm)):
            tmp_wasm[idx] = tmp_wasm[idx].replace("FNAME", f"{name}.wasm")
        with open(f"{COMPILE_DIR}/{name}/Dockerfile_wasm", "w") as f:
            f.writelines(tmp_wasm)

def build_docker():
    gen_docker_file()

    # build native image
    print("Building Linux images...")

    error_log = []

    os.chdir(SRC_DIR)
    for file in tqdm(sorted(os.listdir("."))):
        name = file.split(".")[0]
        cmd = f"docker buildx build -f {CURRENT_DIR}/{COMPILE_DIR}/{name}/Dockerfile_native -t wasmbench/{name}:0.0 ."
        print(cmd)
        r = os.system(cmd)
        if r != 0:
            error_log.append(name)
    os.chdir(CURRENT_DIR)

    # build wasm image
    print("Building Wasm images...")
    for file in tqdm(sorted(os.listdir(SRC_DIR))):
        name = file.split(".")[0]
        os.chdir(f"{COMPILE_DIR}/{name}")
        cmd = f"docker buildx build --platform wasi/wasm32 -f Dockerfile_wasm -t wasmbench/{name}:0.1 ."
        print(cmd)
        r = os.system(cmd)
        if r != 0:
            error_log.append(name)
        os.chdir(CURRENT_DIR)
    os.chdir(CURRENT_DIR)

    if len(error_log) > 0:
        print("Error log:")
        for log in error_log:
            print(log)


if __name__ == "__main__":
    compile()
    build_docker()

