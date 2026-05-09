def solution(n):
    answer = 0
    goal = [0] * (n+1)
    
    goal[0] = 1
    goal[1] = 1
    
    if n >= 2:
        for i in range(2, n+1):
            for j in range(i):
                goal[i] += goal[j] * goal[i-j-1]
    
            
    answer = goal[n]
    return answer