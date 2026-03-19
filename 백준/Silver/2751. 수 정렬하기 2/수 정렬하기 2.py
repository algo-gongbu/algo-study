import sys


#sys.stdin = open("input.txt", "rt")

N = int(sys.stdin.readline().rstrip())
arr = [sys.stdin.readline().rstrip() for _ in range(N)] # List Comprehension 활용!


def solution():
    arr.sort(key = int)
    sys.stdout.write('\n'.join(arr) + '\n')  #SyntaxError: f-string expression part cannot include a backslash

if __name__ == "__main__":
    solution()