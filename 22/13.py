#!/usr/bin/env python2
import sys

part1 = 0
part2 = 0

lines = [l.rstrip() for l in sys.stdin]

def cmp(a, b):
    if isinstance(a, int) and isinstance(b, int):
        return -1 if a < b else 0 if a == b else 1
    if isinstance(a, int): return cmp([a], b)
    if isinstance(b, int): return cmp(a, [b])
    for x,y in zip(a,b):
        r = cmp(x,y)
        if r != 0:
            return r
    if len(a) == len(b):
        return 0
    if len(a) < len(b):
        return -1
    return 1

all = []

for i in range(0, len(lines), 3):
    a = eval(lines[i+1])
    b = eval(lines[i+2])
    all.append(a)
    all.append(b)
    if cmp(a, b) <= 0:
        part1 += i//3 + 1

all.append([[2]])
all.append([[6]])

all.sort(cmp=cmp)
x = all.index([[2]])
y = all.index([[6]])
part2 = (x+1) * (y+1)

print(part1)
print(part2)
