import os


cnt_line = 0
for root, dirs, files in os.walk('../UnmannedSupermarketSimulationSystem'):
    for file in files:
        if file[-2:] == '.h' or file[-4:] == '.cpp':
            path = os.path.join(root, file)
            if path[:len(root)].count('/') == 1:
                try:
                    cnt_line += len(open(path).readlines())
                    print(path)
                except:
                    pass
print(cnt_line)