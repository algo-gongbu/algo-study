def solution(s):
    answer = 0
    num = s.split()
    q = []
    for i in num:
        if i != 'Z':
            q.append(int(i))
        else:
            q.pop()
            
    answer = sum(q)
    return answer