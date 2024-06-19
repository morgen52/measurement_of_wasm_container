# Measurement Study of Wasm-based Container Runtime

An artifact for our paper entitled "WebAssembly for Container Runtime: Are We There Yet?".

## Prerequirements
- Docker Desktop with Wasm support (Version 4.28.0)
- Wasm Runtimes: Wasmer (v4.1.2), Wasmtime(v17.0)
- Emscripten SDK (Version 3.1.44)
- Gcc (Ubuntu 11.4.0-1ubuntu1~22.04)
- Python3 with packages(`matplotlib`, `numpy`, `tqdm`, `psutil`, `docker`, `json`)

## Benchmarks

- polybench: see [polybench/README.md](polybench/README.md)
- wasmbench: see [wasmbench/README.md](wasmbench/README.md)
- system access benchmarks: see [system_access/README.md](system_access/README.md)

## Contact

If you have any question, please contact lmg@pku.edu.cn