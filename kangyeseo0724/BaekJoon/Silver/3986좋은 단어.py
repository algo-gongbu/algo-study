import sys

input = sys.stdin.readline

def solve():
    n = int(input())
    count = 0
    
    for _ in range(n):
        word = input().strip()
        stack = []
        
        for char in word:
            if stack and stack[-1] == char:
                stack.pop()
            else:
                stack.append(char)
        
        if not stack:
            count += 1
            
    print(count)

solve()