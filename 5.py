import sys

s = set()
mi = 1000000
m = 0
for line in sys.stdin.read().strip().split("\n"):
    line = line.replace("B", '1').replace("F", "0").replace("R", "1").replace("L", "0")
    val = int(line, 2)
    s.add(val)
    m = max(m, val)
    mi = min(mi, val)

print(m)

for i in range(mi, 100000):
    if i not in s:
        print(i)
        exit()
