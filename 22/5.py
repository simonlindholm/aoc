import sys
import copy

nine = 9

lines = []
while True:
    x = input()
    if not x:
        break
    lines.append(x)
tower = [[] for _ in range(nine)]
for l in lines[:-1]:
    print(l)
    for i in range(nine):
        c = l[i*4+1]
        if c != ' ':
            tower[i].append(c)
for i in range(nine):
    tower[i] = tower[i][::-1]

lines = [l.rstrip() for l in sys.stdin]

for day in (1, 2):
    backup = copy.deepcopy(tower)
    for line in lines:
        p = line.split()
        a = int(p[1])
        b = int(p[3]) - 1
        c = int(p[5]) - 1
        move = tower[b][-a:]
        tower[b] = tower[b][:-a]
        if day == 1:
            move = move[::-1]
        for x in move:
            tower[c].append(x)

    res = ""
    for i in range(nine):
        res += tower[i][-1]
    print(res)

    tower = backup 
