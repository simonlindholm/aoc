import sys

part1 = 0
part2 = 0

lines = []
for line in sys.stdin:
    line = line.strip()
    a = line[:len(line)//2]
    b = line[len(line)//2:]
    l = list(set(a) & set(b))
    c = l[0]
    if 'a' <= c <= 'z':
        r = ord(c) - 96
    else:
        r = ord(c) - 64 + 26
    part1 += r
    if line:
        lines.append(line)

for i in range(0, len(lines), 3):
    a,b,c = lines[i:i+3]
    l = list(set(a) & set(b) & set(c))[0]
    c = l[0]
    if 'a' <= c <= 'z':
        r = ord(c) - 96
    else:
        r = ord(c) - 64 + 26
    part2 += r

print(part1)
print(part2)
