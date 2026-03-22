import sys

n, c = map(int, sys.stdin.readline().split())

nums = list(map(int, sys.stdin.readline().split()))

count_dict = {}
first_dict = {}

for i in range (n):
    num = nums[i]
    
    if num in count_dict:
        count_dict[num] += 1
    else:
        count_dict[num] = 1
        first_dict[num] = i
        
keys = list(count_dict.keys())

keys.sort(key=lambda x: (-count_dict[x], first_dict[x]))

for num in keys:
    for _ in range(count_dict[num]):
        print(num, end = ' ')

