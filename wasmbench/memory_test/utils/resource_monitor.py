import psutil
import os
import time

def stop_containers():
    os.system("docker stop $(docker ps -aq)")
    os.system("docker rm $(docker ps -aq)")
    time.sleep(2)

def cool():
    all_containers = os.popen("docker ps -aq | wc -l").read().strip()
    try:
        all_containers = int(all_containers)
    except:
        pass
    if all_containers == 0:
        return True
    stop_containers()
    return False

def resource_monitor(interval=0.5, repeat=5): # -> cpu, memory
    memories = []
    cpus = []
    for i in range(repeat):
        cpu_percent = psutil.cpu_percent(interval=interval)
        memory = psutil.virtual_memory().used / 1024 / 1024 # MiB
        cpus.append(cpu_percent)
        memories.append(memory) 
    return max(cpus), max(memories)
    