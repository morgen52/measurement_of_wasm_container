# compile Wasm
cd ./wasm
cargo build --target wasm32-wasi --release
cp ./target/wasm32-wasi/release/wasm.wasm ./wasm_docker/wasm.wasm
cd wasm_docker
docker buildx build -f Dockerfile_wasm --platform wasi/wasm32 -t filesize:0.1 .

cd ../..

# compile native
cd ./native
cargo build --release
cp ./target/release/native ./native
docker buildx build -f Dockerfile_native -t filesize:0.0 .
cd ..
