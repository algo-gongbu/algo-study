import sys


#sys.stdin = open("input.txt", "rt")

N = int(sys.stdin.readline().rstrip())
arr = [sys.stdin.readline().rstrip().split() for _ in range(N)] # List Comprehension 활용!


def solution():
    stack = []
    
    for inst in arr:
        if inst[0] == 'push':
            stack.append(inst[1])
        elif inst[0] == 'pop':
          if len(stack) == 0:
             answer = -1
          else: 
             answer = stack.pop()
          print(answer)
        elif inst[0] == 'size':
          print(len(stack))
        elif inst[0] == 'empty':
          if len(stack) == 0:
             answer = 1 
          else: 
             answer = 0
          print(answer)
        elif inst[0] == 'top':
          if not stack:
             answer = -1
          else: 
             answer = stack[-1]
          print(answer)

if __name__ == "__main__":
    solution()