input()

a = 0
b = 1

for i,x in enumerate(input().split(",")):
    if x == 'x':
        continue
    x = int(x)
    nb = b
    while (a + i) % x:
        a += b
    while b % x:
        b += nb

print(a)
