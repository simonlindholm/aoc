import sys
from collections import defaultdict
mem = defaultdict(int)
mask1 = 0
mask2 = 0
for line in sys.stdin:
    line = line.strip()
    if line.startswith("mask = "):
        m = line.split()[-1]
        mask1 = int(m.replace("X", "0"), 2)
        mask2 = int(m.replace("X", "1"), 2)
    else:
        addr = int(line[4:].split("]")[0])
        val = int(line.split()[-1])
        # part 1:
        # val &= mask2
        # val |= mask1
        # mem[addr] = val

        x = mask2 ^ mask1
        addr |= mask1
        mem[addr] = val
        i = x
        while i > 0:
            mem[addr ^ i] = val
            i -= 1
            i &= x

res = 0
for key, val in mem.items():
    res += val
print(res)
