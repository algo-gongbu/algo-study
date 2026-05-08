def solution(k, m, score):
    answer = 0
    case = len(score) // m
    score.sort(reverse=True)
    i = 0
    for _ in range(case):
        answer += (min(score[i:i+m])*m)
        i += m

    return answer