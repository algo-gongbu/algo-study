def solution(a, b):
    answer = 0
    st = min(a,b)
    en = max(a,b)
    for i in range(st, en+1):
        answer += i
    return answer