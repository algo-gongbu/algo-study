import sys
n = int(sys.stdin.readline())
people = []

for _ in range(n):
    w, h = map(int, sys.stdin.readline().split())
    people.append((w, h))
    
for i in range(len(people)):
    lank = 1
    for j in range(len(people)):
        if i == j:
            continue
        elif people[i][0] < people[j][0] and people[i][1] < people[j][1]:
            lank += 1
    
    print(lank, end = ' ')