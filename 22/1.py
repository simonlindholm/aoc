import sys
m = []
for a in sys.stdin.read().split("\n\n"):
    m.append(sum(map(int, a.split())))
m.sort()
print(m[-1])
print(m[-3] + m[-2] + m[-1])
