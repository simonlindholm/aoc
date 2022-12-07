import sys

part1 = 0
part2 = 10**12

lines = [l.strip() for l in sys.stdin]

cwd = "/"
contents = {}
i = 0
while i < len(lines):
    line = lines[i]
    assert line.startswith('$')
    cmd = line[2:]
    i += 1
    output = []
    while i < len(lines) and not lines[i].startswith('$'):
        output.append(lines[i])
        i += 1
    if cmd.startswith("cd "):
        to = cmd[3:]
        if to.startswith("/"):
            cwd = to
        else:
            for x in to.split("/"):
                assert x, to
                if x == "..":
                    cwd = "/".join(cwd.split("/")[:-1])
                    if cwd == "":
                        cwd = "/"
                else:
                    if cwd == "/":
                        cwd = ""
                    cwd += "/" + x
    else:
        assert cmd == "ls", cmd
        conts = {}
        for line in output:
            a,b = line.split()
            conts[b] = a
        assert cwd.startswith("/")
        contents[cwd] = conts

s = 0
for d2 in contents:
    for b,a in contents[d2].items():
        if a != "dir":
            s += int(a)

needed = s - 40000000

for d in contents:
    s = 0
    for d2 in contents:
        if d2.startswith(d):
            for b,a in contents[d2].items():
                if a != "dir":
                    s += int(a)
    if s <= 100000:
        part1 += s
    if s >= needed:
        part2 = min(part2, s)

print(part1)
print(part2)
