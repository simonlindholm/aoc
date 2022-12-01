n = int(input())
best = 10**10
res = None

# Ported from KACTL

def euclid(a, b):
        x = 1
        yy = x
        y = 0
        xx = y
        while b:
                q = a // b
                t = b
                b = a % b
                a = t
                t = xx
                xx = x - q * xx
                x = t
                t = yy
                yy = y - q * yy
                y = t
        return x, y, a

def crt(a, m, b, n):
        if n > m:
            a,b = b,a; m,n = n,m
        x, y, g = euclid(m, n)
        assert (a - b) % g == 0
        x = (b - a) % n * x % n // g * m + a
        return (x + m*n//g if x < 0 else x), m*n//g

a = 0
b = 1

for i,x in enumerate(input().split(",")):
    if x == 'x':
        continue
    f = int(x)
    g = (-n) % f
    if g < best:
        best = g
        res = g * f

    a,b = crt(a,b, (-i) % f, f)


print(res, best)
print(a)
