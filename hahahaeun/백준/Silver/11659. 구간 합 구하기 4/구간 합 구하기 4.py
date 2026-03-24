import sys

input = sys.stdin.readline

n, m = map(int, input().split())

num = list(map(int, input().split()))

num_sum = 0
numbers = [0]
for x in num:
    num_sum += x
    numbers.append(num_sum)

for _ in range(m):
    i, j = map(int, input().split())

    print(numbers[j]-numbers[i-1])
