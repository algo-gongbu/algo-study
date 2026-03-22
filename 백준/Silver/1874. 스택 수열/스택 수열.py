import sys

n = int(sys.stdin.readline())

target = []

for _ in range(n):
    target.append(int(sys.stdin.readline()))
    
stack = []
op = []
current = 1
possible = True

for num in target:
    while current <= num:
        stack.append(current)
        op.append('+')
        current += 1
    
    if stack[-1] == num:
        stack.pop()
        op.append('-')
    else:
        possible = False
        break
    
if possible:
    print('\n'.join(op))
else:
    print("NO")