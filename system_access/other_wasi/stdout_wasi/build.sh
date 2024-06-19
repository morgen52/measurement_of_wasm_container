cargo build --target wasm32-wasi --release
cp ./target/wasm32-wasi/release/stdout_wasi.wasm ./wasm_docker/
cd ./wasm_docker
docker buildx build -f Dockerfile_wasm --platform wasi/wasm32 -t liminfinity/stdout_wasi:0.1 .

cd ../
cargo build --release
docker buildx build -f Dockerfile_native -t liminfinity/stdout_wasi:0.0 .
