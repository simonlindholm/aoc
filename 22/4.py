import sys

part1 = 0
part2 = 0

for line in sys.stdin:
    a,b = line.strip().split(",")
    a1,a2 = map(int, a.split("-"))
    b1,b2 = map(int, b.split("-"))
    if a1 <= b1 and b2 <= a2:
        part1 += 1
    elif b1 <= a1 and a2 <= b2:
        part1 += 1

    if a2 < b1 or b2 < a1:
        pass
    else:
        part2 += 1


print(part1)
print(part2)
