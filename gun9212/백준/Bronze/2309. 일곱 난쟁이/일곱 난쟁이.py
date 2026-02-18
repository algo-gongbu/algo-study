import sys
from itertools import combinations
input = sys.stdin.readline

height = [0] * 10
num =0

for i in range(1,10):
    height[i] = int(input())

for comb in combinations(height[1:10], 7):
    if sum(comb) == 100:
        for j in sorted(comb):
            print(j)
        break
