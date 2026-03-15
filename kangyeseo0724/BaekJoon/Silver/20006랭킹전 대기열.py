import sys
from typing import List

p, m = map(int, sys.stdin.readline().split())
rooms: List[List] = []

for _ in range(p):
    l, n = sys.stdin.readline().split()
    l = int(l)
    
    entrance = False
    
    for r in rooms:
        if len(r) < m and abs(r[0][0] - l) <= 10:
            r.append((l, n))
            entrance = True
            break
    
    if not entrance:
        rooms.append([(l, n)])
        
for r in rooms:
    if len(r) == m:
        print("Started!")
    else:
        print("Waiting!")
            
    r.sort(key=lambda x: x[1])
    for p in r:
        print(p[0], p[1])