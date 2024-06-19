import os
import time
import datetime
import json
import docker

from tqdm import tqdm

from utils.configs import docker_url

client = docker.DockerClient(base_url=docker_url)

def time_duration(start_time, end_time):
    start_time = datetime.datetime.strptime(start_time, '%M:%S.%f')
    end_time = datetime.datetime.strptime(end_time, '%M:%S.%f')
    ms = (end_time - start_time).total_seconds() * 1000

    if ms < 0: # cross an hour
        ms += 3600 * 1000
    if ms < 0: # cross a day
        ms += 23 * 3600 * 1000
    return ms

def single_experiment(mode='native', image='liminfinity/time_wasi', runtime="wasmer"):
    if runtime == "":
        runtime = "wasmer"

    print(f'Running {image} in {mode} mode ({runtime}) ...')

    start_time = datetime.datetime.now().strftime('%M:%S.%f')
    if mode == 'native':
        container = client.containers.run(f'{image}:0.0').decode('utf-8')
    elif mode == 'wasm':
        container = client.containers.run(f'{image}:0.1', runtime=f'io.containerd.{runtime}.v1', platform='wasi/wasm32').decode('utf-8')
    elif mode == 'native_wasm':
        fname = image.split('/')[-1]
        container = os.popen(f"{runtime} {fname}/docker/{fname}.wasm").read()
    end_compl_time = datetime.datetime.now().strftime('%M:%S.%f')
    
    log = container.strip().split('\n')

    start_compl_time = log[0].split("time:")[-1]
    end_time = log[-1].split("time:")[-1]

    client.containers.prune()

    return {
        "startup": time_duration(start_time, start_compl_time),
        "execution": time_duration(start_compl_time, end_time),
        "e2e": time_duration(start_time, end_compl_time)
    }


def experiment(runtime="wasmer"):

    LOG_DIR = f'measured_results'
    
    images = ['liminfinity/time_wasi', 'liminfinity/stdout_wasi', 'liminfinity/rand_wasi']
    iterations = 20
            
    results = {}

    for image in images:
        results[image] = {"native": {}, "wasm": {}, "native_wasm": {}}
        tmp = {"native": [], "wasm": [], "native_wasm": []}
        for _ in tqdm(range(iterations)):
            tmp['native'].append(single_experiment('native', image, runtime))
            tmp['wasm'].append(single_experiment('wasm', image, runtime))
            tmp['native_wasm'].append(single_experiment('native_wasm', image, runtime))
            time.sleep(0.1)
        
        results[image]['native'] = {
            "startup": sum([x['startup'] for x in tmp['native']])/len(tmp['native']),
            "execution": sum([x['execution'] for x in tmp['native']])/len(tmp['native']),
            "e2e": sum([x['e2e'] for x in tmp['native']])/len(tmp['native'])
        }
        results[image]['wasm'] = {
            "startup": sum([x['startup'] for x in tmp['wasm']])/len(tmp['wasm']),
            "execution": sum([x['execution'] for x in tmp['wasm']])/len(tmp['wasm']),
            "e2e": sum([x['e2e'] for x in tmp['wasm']])/len(tmp['wasm'])
        }
        results[image]['native_wasm'] = {
            "startup": sum([x['startup'] for x in tmp['native_wasm']])/len(tmp['native_wasm']),
            "execution": sum([x['execution'] for x in tmp['native_wasm']])/len(tmp['native_wasm']),
            "e2e": sum([x['e2e'] for x in tmp['native_wasm']])/len(tmp['native_wasm'])
        }

    with open(f'{LOG_DIR}/results_{runtime}.json', 'w') as f:
        json.dump(results, f, indent=2)

if __name__ == '__main__':
    runtimes = ["wasmtime", "wasmer"]
    for r in runtimes:
        experiment(r)