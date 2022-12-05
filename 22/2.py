import sys
res = 0
for line in sys.stdin:
    a,b = line.split()
    a = ord(a) - ord('A')
    b = ord(b) - ord('X')
    w = b
    b = (w - 1 + a) % 3
    # w = (b - a + 1) % 3
    res += w * 3 + b + 1
print(res)
