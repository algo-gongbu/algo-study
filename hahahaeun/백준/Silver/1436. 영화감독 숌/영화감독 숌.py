import sys

input = sys.stdin.readline

n = int(input())

num = 666
i = 0
while i != n:
    if '666' in str(num):
        i += 1
    num += 1

print(num-1)