#!/bin/bash
COMPILED_DIR="../compiled"

bp=${1:-0} # breakpoint to skip ahead, default value is 0
runtime=${2:-wasmer} # runtime to use, default is wasmer

# read the keys from the COMPILED_DIR
keys=$(ls $COMPILED_DIR)

i=1
warmup=1
for key in $keys; do

    if [ $i -lt $bp ]; then
        i=$((i + 1))
        continue
    fi

    echo $i: $key
    if [ $warmup -eq 1 ]; then # warm up
        python3 memory_monitor_wasmvm.py --key $key --warmup 1 --runtime $runtime
        warmup=0
    else
        python3 memory_monitor_wasmvm.py --key $key --runtime $runtime
    fi
    i=$((i + 1))
done

