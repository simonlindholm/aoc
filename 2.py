import sys

res = 0

for line in sys.stdin.read().strip().split("\n"):
    pat, pw = line.split(": ")
    ran, let = pat.split(" ")
    f, t = ran.split("-")
    f = int(f)
    t = int(t)
    # if f <= pw.count(let) <= t:
    if [pw[f-1], pw[t-1]].count(let) == 1:
        res += 1

print(res)
