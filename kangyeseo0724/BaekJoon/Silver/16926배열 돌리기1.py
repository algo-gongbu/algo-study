import sys
from collections import deque

def solve():
    input = sys.stdin.readline
    n, m, r = map(int, input().split())
    matrix = [list(map(int, input().split())) for _ in range(n)]

    layers = min(n, m) // 2

    for i in range(layers):
        queue = deque()

        for j in range(i, m - i):
            queue.append(matrix[i][j])
        for j in range(i + 1, n - i):
            queue.append(matrix[j][m - 1 - i])
        for j in range(m - 2 - i, i - 1, -1):
            queue.append(matrix[n - 1 - i][j])
        for j in range(n - 2 - i, i, -1):
            queue.append(matrix[j][i])

        queue.rotate(-r)

        for j in range(i, m - i):
            matrix[i][j] = queue.popleft()

        for j in range(i + 1, n - i):
            matrix[j][m - 1 - i] = queue.popleft()

        for j in range(m - 2 - i, i - 1, -1):
            matrix[n - 1 - i][j] = queue.popleft()

        for j in range(n - 2 - i, i, -1):
            matrix[j][i] = queue.popleft()

    for row in matrix:
        print(*(row))

solve()