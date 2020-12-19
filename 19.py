import sys

gr = {}
seen = {}

def matches(ind, inp):
    if (ind, inp) in seen:
        return seen[(ind, inp)]
    e = gr[ind]
    if isinstance(e, str):
        return inp == e
    for cd in e:
        if isinstance(cd, int):
            if matches(cd, inp):
                seen[(ind, inp)] = True
                return True
        elif len(cd) == 2:
            c,d = cd
            for i in range(1,len(inp)):
                if matches(c, inp[:i]) and matches(d, inp[i:]):
                    seen[(ind, inp)] = True
                    return True
        else:
            c,d,f = cd
            for i in range(1,len(inp)):
                for j in range(i+1,len(inp)):
                    if matches(c, inp[:i]) and matches(d, inp[i:j]) and matches(f, inp[j:]):
                        seen[(ind, inp)] = True
                        return True
    seen[(ind, inp)] = False
    return False

res = 0
two = False
for line in sys.stdin:
    line = line.strip()
    if not line:
        two = True
        gr[8] = [42, (42, 8)]
        gr[11] = [(42,31), (42,11,31)]
    elif not two:
        a,b = line.split(": ")
        a = int(a)
        if b.startswith("\""):
            gr[a] = b[1:-1]
        else:
            li = []
            for x in b.split(" | "):
                y = x.split()
                if len(y) == 1:
                    li.append(int(y[0]))
                else:
                    c,d = y
                    li.append((int(c), int(d)))
            gr[a] = li
    else:
        if matches(0, line):
            res += 1
print(res)
