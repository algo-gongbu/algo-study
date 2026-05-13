def solution(n, s, a, b, fares):
    answer = float('inf')
    spot = [[float('inf')] * (n+1) for _ in range(n+1)]
    for i in fares:
        start = i[0]
        end = i[1]
        fee = i[2]
        spot[start][end] = fee
        spot[end][start] = fee
    
    for i in range(1, n+1):
        spot[i][i] = 0
            
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if spot[i][j] > spot[i][k] + spot[k][j]:
                    spot[i][j] = spot[i][k] + spot[k][j]
    for k in range(1, n+1):
        if answer > spot[s][k] + spot[k][a] + spot[k][b]:
            answer = spot[s][k] + spot[k][a] + spot[k][b]
    
    return answer