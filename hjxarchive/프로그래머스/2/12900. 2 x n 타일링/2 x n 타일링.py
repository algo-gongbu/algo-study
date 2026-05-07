def solution(n):
    rec = [0 for _ in range(n)]
    rec[0] = 1
    rec[1] = 2
    
    for i in range(2,n):
        rec[i] = rec[i-1] + rec[i-2]
        rec[i] = rec[i]% 1000000007
    answer = rec[n-1] % 1000000007
    return answer