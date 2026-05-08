def solution(board):
    answer = 0
    spot = []
    n = len(board)
    check = [[True for _ in range(n)] for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                spot.append((j,i))
                
    around = [(0,1),(0,-1),(1,0),(-1,0),(1,-1),(-1,1),(-1,-1),(1,1)]
    
    for i in spot:
        check[i[1]][i[0]] = False
        for j in range(8):
            nx = i[0] + around[j][0]
            ny = i[1] + around[j][1]

            if 0<=nx<n and 0<=ny<n and check[ny][nx]:
                check[ny][nx] = False
    
    for i in range(n):
        for j in range(n):
            if check[i][j]:
                answer += 1
            
    return answer