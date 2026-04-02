import sys
from itertools import accumulate

#sys.stdin = open("input.txt", "rt")

def solution():
    N, M = map(int,sys.stdin.readline().rstrip().split())
    nums = list(map(int, sys.stdin.readline().split()))
    acc_sum = [0]
    acc_sum.extend(list(accumulate(nums))) #extend는 항상 none 반환 원본 함수만 수정
    
    for _ in range(M):
        i, j = map(int, sys.stdin.readline().rstrip().split())  
        sys.stdout.write(str(acc_sum[j] - acc_sum[i - 1]) + "\n")
        
if __name__ == "__main__":
    solution()