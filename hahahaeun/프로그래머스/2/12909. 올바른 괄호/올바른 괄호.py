def solution(s):
    q = []
    
    for i in s:
        if i == '(':
            q.append(i)
        else:
            if q:
                q.pop()
            else:
                return False
    if q:
        return False

    return True