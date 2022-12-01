import sys

class Add:
    def __init__(self, state=None):
        self.state = state

    def __radd__(self, other):
        return Add(other)

    def __add__(self, other):
        return self.state + other

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

part1 = 0
part2 = 0
for line in sys.stdin:
    line = line.strip()
    part1 += eval(line.replace("+", "BLAH").replace("*", "+MUL+").replace("BLAH", "+ADD+"))
    part2 += eval(line.replace("+", "BLAH").replace("*", "+MUL+").replace("BLAH", "*ADD*"))

print(part1)
print(part2)
