import sys

vals = set()
for line in sys.stdin.read().strip().split("\n"):
    vals.add(int(line))

for x in vals:
    if 2020 - x in vals:
        print(x * (2020 - x))
        break

for x in vals:
    for y in vals:
        if 2020 - x - y in vals:
            print(x * y * (2020 - x - y))
            exit()
