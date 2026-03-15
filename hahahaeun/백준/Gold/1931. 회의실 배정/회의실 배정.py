import sys
input = sys.stdin.readline

n = int(input())

goal = []
for _ in range(n):
    a, b = map(int, input().split())
    goal.append((a, b))
goal.sort(key=lambda x: (x[1], x[0]))

count = 0
end = 0

for s, e in goal:
    if s >= end:
        count += 1
        end = e

print(count)