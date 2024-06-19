

## custom config

docker_url = "unix:///home/morgen/.docker/desktop/docker.sock"

## fixed config

specific_compile_cmd = {
    "linear-algebra/solvers/gramschmidt/gramschmidt.c":{
        "gcc": "gcc -O3 -I utilities -I linear-algebra/solvers/gramschmidt utilities/polybench.c linear-algebra/solvers/gramschmidt/gramschmidt.c -DPOLYBENCH_TIME -o ../compiled/linear-algebra/solvers/gramschmidt/gramschmidt -lm",
        "wasm": "emcc -O3 -s WASM=1 -s INITIAL_MEMORY=67108864 -I utilities -I linear-algebra/solvers/gramschmidt utilities/polybench.c linear-algebra/solvers/gramschmidt/gramschmidt.c -DPOLYBENCH_TIME -DNDEBUG -o ../compiled/linear-algebra/solvers/gramschmidt/gramschmidt.wasm -lm",
    },
    "datamining/correlation/correlation.c":{
        "gcc": "gcc -O3 -I utilities -I datamining/correlation utilities/polybench.c datamining/correlation/correlation.c -DPOLYBENCH_TIME -o ../compiled/datamining/correlation/correlation -lm",
        "wasm": "emcc -O3 -s WASM=1 -s INITIAL_MEMORY=67108864 -I utilities -I datamining/correlation utilities/polybench.c datamining/correlation/correlation.c -DPOLYBENCH_TIME -DNDEBUG -o ../compiled/datamining/correlation/correlation.wasm -lm",
    },
    "medley/deriche/deriche.c":{
        "gcc": "gcc -O3 -I utilities -I medley/deriche utilities/polybench.c medley/deriche/deriche.c -DPOLYBENCH_TIME -o ../compiled/medley/deriche/deriche -lm",
        "wasm": "emcc -O3 -s WASM=1 -s INITIAL_MEMORY=142606336 -I utilities -I medley/deriche utilities/polybench.c medley/deriche/deriche.c -DPOLYBENCH_TIME -DNDEBUG -o ../compiled/medley/deriche/deriche.wasm -lm",
    }
}
