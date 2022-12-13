import sys

part1 = 0
part2 = 0

lines = [l.rstrip() for l in sys.stdin]

for line in lines:
    a,b = map(int, line.split())

print(part1)
print(part2)
