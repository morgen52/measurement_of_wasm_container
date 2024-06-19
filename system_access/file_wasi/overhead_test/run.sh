
LOG_DIR=$(pwd)/measured_results/logs

cd ./file-wasm/wasm_docker

# run wasm vm
wasmtime --dir=. file-wasm.wasm > $LOG_DIR/log_wasm_vm_wasmtime.txt
wasmer --dir=. file-wasm.wasm > $LOG_DIR/log_wasm_vm_wasmer.txt

# run wasm container
cd ..
docker compose -f docker-compose-wasmtime.yaml up > $LOG_DIR/log_wasm_container_wasmtime.txt
docker compose down
docker compose -f docker-compose-wasmer.yaml up > $LOG_DIR/log_wasm_container_wasmer.txt
docker compose down

# run native
cd ../file-native
target/release/file-native > $LOG_DIR/log_native.txt

docker compose up > $LOG_DIR/log_native_container.txt
docker compose down
