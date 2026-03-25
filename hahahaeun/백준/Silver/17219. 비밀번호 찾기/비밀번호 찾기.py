import sys

input = sys.stdin.readline

n, m = map(int, input().split())

info = {}

for _ in range(n):
    site, pw = input().split()
    
    info[site] = pw
    
for i in range(m):
    search = input().strip()
       
    if search in info:
        print(info[search])