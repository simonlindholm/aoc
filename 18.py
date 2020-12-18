import sys

class Add:
    def __init__(self, state=None):
        self.state = state

    def __rmul__(self, other):
        return Add(other)

    def __mul__(self, other):
        return self.state + other

ADD = Add()

class Mul:
    def __init__(self, state=None):
        self.state = state

    def __radd__(self, other):
        return Mul(other)

    def __add__(self, other):
        return self.state * other

MUL = Mul()

res = 0
for line in sys.stdin:
    line = line.strip()
    res += eval(line.replace("+", "BLAH").replace("*", "+MUL+").replace("BLAH", "*ADD*"))

print(res)
