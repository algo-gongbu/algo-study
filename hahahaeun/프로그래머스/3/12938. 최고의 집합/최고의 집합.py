def solution(n, s):
    answer = []
    if n > s:
        answer.append(-1)
    else:
        answer = []
        value = s // n
        rest = s % n
        
        answer = [value] * n   
        for i in range(n-1, -1, -1):
            if rest == 0:
                break
            else:
                answer[i] += 1
                rest -= 1
    
    return answer
