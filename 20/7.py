import sys

ed = {}

for line in sys.stdin:
    line = line.strip("\n.")
    parts = line.split()
    a = ' '.join(parts[:2])
    b,c = line.split("contain ")
    eds = []
    for j in c.split(", "):
        if j.startswith("no other"):
            continue
        desc = ' '.join(j.split()[1:3])
        co = int(j.split()[0])
        print(a, co, desc)
        eds.append((co, desc))
    ed[a] = eds

seen = {}
def rec(a):
    if a == 'shiny gold':
        return True
    if a in seen:
        return seen[a]
    for _,ch in ed[a]:
        if rec(ch):
            seen[a] = True
            return True
    seen[a] = False
    return False

res = 0
for a in ed:
    res += rec(a)

res -= 1
print(res)

seen = {}
def rec(a):
    if a in seen:
        return seen[a]
    sum = 1
    for co,ch in ed[a]:
        sum += co*rec(ch)
    seen[a] = sum
    return sum

print(rec('shiny gold') - 1)

