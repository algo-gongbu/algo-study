import sys

n, m = map(int, sys.stdin.readline().split())

s = set()

for _ in range (n):
    s.add(sys.stdin.readline().strip())
    
count = 0

for _ in range(m):
    check = sys.stdin.readline().strip()
    
    if check in s:
        count += 1

print(count)