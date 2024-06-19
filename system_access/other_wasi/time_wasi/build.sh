cargo clean
cargo build --target wasm32-wasi --release

# Build Wasm Docker Image
cp ./target/wasm32-wasi/release/time_wasi.wasm ./wasm_docker/
cd ./wasm_docker
docker buildx build -f Dockerfile_wasm --platform wasi/wasm32 -t liminfinity/time_wasi:0.1 .

# Build Linux Docker Image
cd ../
cargo build --release
docker buildx build -f Dockerfile_native -t liminfinity/time_wasi:0.0 .
