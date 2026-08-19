from itertools import permutations

def solution(k, dungeons):
    answer = []
    init = k
    cases = [per for per in permutations(dungeons)]
    
    for case in cases:
        count = 0
        k = init
        for c in case:
            if k >= c[0]:
                count += 1
                k -= c[1]
        answer.append(count)
        
    print(case)
    
    return max(answer)