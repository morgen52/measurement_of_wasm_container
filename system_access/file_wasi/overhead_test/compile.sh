# compile Wasm
cd ./file-wasm
cargo build --target wasm32-wasi --release
cp target/wasm32-wasi/release/file-wasm.wasm wasm_docker/file-wasm.wasm
cd ./wasm_docker

docker buildx build -f Dockerfile_wasm --platform wasi/wasm32 -t filetest/file-wasm:0.1 .

cd ../..

# compile native
cd ./file-native
cargo build --release
docker buildx build -f Dockerfile_native --platform linux/amd64 -t filetest/file-native:0.1 .
