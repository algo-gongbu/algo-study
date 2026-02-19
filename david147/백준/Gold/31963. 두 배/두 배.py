import math
import sys
input = sys.stdin.readline

n = int(input())
s = [*map(int, input().split())]

cnt = 0; exp_prev = 0; exp_cur = 0;
for i in range(1, len(s)):
    diff = 0;
    
    if s[i - 1] <= s[i]:
        temp = s[i - 1]
        while temp * 2 <= s[i]:
            temp *= 2
            diff += 1
        
        exp_cur = max(0, exp_prev - diff)
    
    elif s[i - 1] > s[i]:
        temp = s[i]
        while s[i - 1] > temp:
            temp *= 2
            diff += 1
        
        exp_cur = exp_prev + diff
        
    cnt += exp_cur
    exp_prev = exp_cur
        
print(cnt)