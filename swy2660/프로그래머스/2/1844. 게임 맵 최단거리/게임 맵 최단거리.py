def solution(maps):
    from collections import deque
    
    n = len(maps)
    m = len(maps[0])
    
    queue = deque()
    queue.append((0, 0, 1))  # (x, y, 거리)
    
    # 시작 위치 방문 처리
    maps[0][0] = 0
    
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    
    while queue:
        x, y, dist = queue.popleft()
        
        # 목표 도착
        if x == n - 1 and y == m - 1:
            return dist
        
        # 4방향 탐색
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            # 조건 체크
            if 0 <= nx < n and 0 <= ny < m and maps[nx][ny] == 1:
                maps[nx][ny] = 0  # 방문 처리
                queue.append((nx, ny, dist + 1))
    
    # 도달 못 했을 때
    return -1