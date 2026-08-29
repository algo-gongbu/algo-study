def solution(arr):
    answer = []
    
    for count in arr:
        for _ in range(count):
            answer.append(count)
    return answer