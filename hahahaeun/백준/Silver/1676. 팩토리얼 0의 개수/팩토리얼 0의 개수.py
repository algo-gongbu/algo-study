import sys

input = sys.stdin.readline

n = int(input())
num = 1
i = 2
while i < n+1:
    num *= i
    i+=1

list_num = list(str(num))

count = 0

for j in range(len(list_num) - 1, -1, -1):
    if list_num[j] == '0':
        count += 1
    
    else:
        break

print(count)