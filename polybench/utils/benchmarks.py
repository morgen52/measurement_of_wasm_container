def get_configs():
    allfiles = []
    with open("./benchmarks_list.txt", "r") as f:
        for line in f:
            if line.strip() != "": # skip blank lines
                # generate the name of source, dependency, and result file
                tmp = {
                    "depends": "/".join(line.strip().split("/")[:-1]),
                    "src": line.strip(),
                    "result": "compiled/" + "/".join(line.strip().split("/")[:-1]) + "/" +\
                    line.strip().split("/")[-1].split(".")[0]
                }
                allfiles.append(tmp)
    return allfiles
