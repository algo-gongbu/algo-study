def solution(s):
    answer = []

    for i in range(len(s)):
        if s[i] not in s[:i]:
            answer.append(-1)
        else:
            for j in range(i-1, -1, -1):
                if s[j] == s[i]:
                    answer.append(i-j)
                    break        
    return answer