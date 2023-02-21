import os 
import shutil

# Open the file and add "," to the numbers
f2 = open("mem_dump.txt")
lines = f2.read().splitlines()
f2 = open("mem_dumpx.txt","w")
for line in lines:
	f2.write(line + ",\n")
f2.close()

# set the path as parent path
path_parent = os.path.dirname(os.getcwd())
os.chdir(path_parent)

# open file and keep the required lines from data.h
fname = os.path.join(path_parent,'firmware/include/data.h') 
f = open(fname)
output = []
for line in f:
    if not 'uint64_t data[] = {\n' in line:
        output.append(line)
    elif line =='uint64_t data[] = {\n':
	break
f.close()
f = open(fname, 'w')
f.writelines(output)
f.write('uint64_t data[] = {\n')
f.close()

# read the mem_dumpx and append it to data.h
with open('sim/mem_dumpx.txt') as fp:
    data2 = fp.read()
f1 = open(fname, 'a+')
f1.write(data2)
f1.write('0\n};\n#endif /* DATA_H */')
f1.close()

# delete mem_dumpx.txt
path1 = os.path.join(path_parent,'sim/mem_dumpx.txt') 
os.remove(path1)
#print(os.getcwd())







