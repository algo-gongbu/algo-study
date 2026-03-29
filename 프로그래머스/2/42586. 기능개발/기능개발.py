def solution(progresses, speeds):
    cnt = 0
    answer = []
    for day in range(1,101):
        for i in range(len(speeds)):
            progresses[i] += speeds[i]
        temp = 0
        for i in range(cnt, len(speeds)):
            if progresses[i] >= 100:
                temp += 1
            else:
                break
        
        if temp > 0:
            answer.append(temp)
            cnt += temp

        if cnt == len(speeds):
            break
                
    
    return answer