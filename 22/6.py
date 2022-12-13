import sys

part1 = 0
part2 = 0

line = input()
for i in range(len(line)):
    if len({line[i], line[i+1], line[i+2], line[i+3]}) == 4:
        print(i+4)
        break

for i in range(len(line)):
    if len(set(line[i:i+14])) == 14:
        print(i+14)
        break
