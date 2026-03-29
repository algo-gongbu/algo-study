def solution(arr):
    answer = []
    answer.append(arr[0])
    cnt = 1
    for i in range(1,len(arr)):
        if answer[cnt-1] != arr[i]:
            answer.append(arr[i])
            cnt += 1
        
    return answer