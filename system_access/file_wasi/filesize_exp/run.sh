LOG_DIR=$(pwd)/measured_results

# run Wasm
cd wasm
docker run --rm --runtime=io.containerd.wasmtime.v1 --platform=wasi/wasm32 filesize:0.1 > $LOG_DIR/wasm_container_wasmtime.json
docker run --rm --runtime=io.containerd.wasmer.v1 --platform=wasi/wasm32 filesize:0.1 > $LOG_DIR/wasm_container_wasmer.json

cd wasm_docker
wasmtime --dir=. ./wasm.wasm > $LOG_DIR/wasm_vm_wasmtime.json
wasmer --dir=. ./wasm.wasm > $LOG_DIR/wasm_vm_wasmer.json
cd ../..

# run native
cd native
docker run --rm filesize:0.0 > $LOG_DIR/native_container.json

cd native
./native > $LOG_DIR/native.json
cd ../..