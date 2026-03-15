import sys

input = sys.stdin.readline

n = int(input())
list1 = []

for _ in range(n):
    num = input().strip()
    list1.append(int(num))

list1.sort()

for i in list1:
    print(i)

