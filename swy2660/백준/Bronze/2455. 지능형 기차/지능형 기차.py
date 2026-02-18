import sys
input = sys.stdin.readline

N1, M1 = map(int, input().split())
N2, M2 = map(int, input().split())
N3, M3 = map(int, input().split())
N4, M4 = map(int, input().split())

max_passengers = 0
current_passengers = 0

for i in range(4):
    if i == 0:
        current_passengers += M1 - N1
    elif i == 1:
        current_passengers += M2 - N2
    elif i == 2:
        current_passengers += M3 - N3
    else:
        current_passengers += M4 - N4
    
    max_passengers = max(max_passengers, current_passengers)

print(max_passengers)
