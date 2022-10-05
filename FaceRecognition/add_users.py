import os

for root, dirs, files in os.walk('orl_faces'):
    content = open('../data/users.txt', 'r').read()
    with open('../data/users.txt', 'w') as f:
        f.write(content)
        for d in dirs:
            user_str = f'{d},1,0.000000'
            f.write('\n' + user_str)
