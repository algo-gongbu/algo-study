import heapq
import sys

input = sys.stdin.readline

n = int(input())
min_heap = []
max_heap = []
problems = {}

for _ in range(n):
    p, l = map(int, input().split())
    heapq.heappush(min_heap, (l, p))
    heapq.heappush(max_heap, (-l, -p))
    problems[p] = l

m = int(input())
for _ in range(m):
    command = input().split()
    
    if command[0] == 'add':
        p, l = int(command[1]), int(command[2])
        heapq.heappush(min_heap, (l, p))
        heapq.heappush(max_heap, (-l, -p))
        problems[p] = l
        
    elif command[0] == 'recommend':
        if command[1] == '1':
            while -max_heap[0][1] not in problems or problems[-max_heap[0][1]] != -max_heap[0][0]:
                heapq.heappop(max_heap)
            print(-max_heap[0][1])
        else:
            while min_heap[0][1] not in problems or problems[min_heap[0][1]] != min_heap[0][0]:
                heapq.heappop(min_heap)
            print(min_heap[0][1])
            
    elif command[0] == 'solved':
        p = int(command[1])
        if p in problems:
            del problems[p]