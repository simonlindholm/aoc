import sys

# s = 0
# for part in sys.stdin.read().split("\n\n"):
#     s += len(set(''.join(part.split())))
# print(s)

s = 0
for part in sys.stdin.read().split("\n\n"):
    ps = part.split()
    p = set(ps[0])
    for p2 in ps:
        p &= set(p2)
    s += len(p)
print(s)
