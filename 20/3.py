import sys

grid = sys.stdin.read().strip().split("\n")
m = len(grid[0])
n = len(grid)

def solve(right, down):
    res = [[0] * m for _ in range(n+down)]
    for i in range(n-1, -1, -1):
        for j in range(m):
            res[i][j] = res[i + down][(j + right) % m] + (1 if grid[i][j] == '#' else 0)
    return res[0][0]

print(solve(3, 1))
print(solve(3, 1) * solve(1, 1) * solve(5, 1) * solve(7, 1) * solve(1, 2))
