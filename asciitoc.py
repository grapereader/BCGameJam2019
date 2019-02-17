import sys

varname = sys.argv[1]
path = sys.argv[2]

with open(path, 'r') as file:
    i = 0;
    for line in file:
        print(varname + '[' + str(i) + '] = "' + line.replace("\\", "\\\\").splitlines()[0] + '";')
        i = i + 1;
