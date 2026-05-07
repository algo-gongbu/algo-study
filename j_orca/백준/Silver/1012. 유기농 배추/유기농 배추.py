import sys
from collections import deque

#sys.stdin = open("input.txt", "rt")

#2D-BFS 아키텍처
            
def bfs(start_x, start_y, field, M, N):
    queue = deque([(start_x, start_y)]) # 초기 노드 설정
    #방문 처리
    field[start_x][start_y] = 0
    
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    
    while queue:
        cx, cy = queue.popleft()
        
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if 0 <= nx < M and 0 <= ny < N: #하한도 막아야 젤 뒷 값을 빼오지 않음
                if field[nx][ny] == 1:
                    queue.append((nx, ny))
                    field[nx][ny] = 0
    
    
    

def solution():
    T = int(sys.stdin.readline().rstrip())
    
    for case in range(T):
        M, N, K = map(int, sys.stdin.readline().rstrip().split())
        farm = [[0]*N for _ in range(M)] #[[0]*N]*M을 하면 똑같은 메모리 주소를 보는 리스트가 나옴
        
        for _ in range(K):
            loc_x, loc_y = map(int, sys.stdin.readline().rstrip().split())
            farm[loc_x][loc_y] = 1
            
        worm = 0
        
        for i in range(M):
            for j in range(N):
                if farm[i][j] == 1:
                    worm += 1
                    bfs(i, j, farm, M, N)
    
        sys.stdout.write(str(worm) + '\n')
    
if __name__ == "__main__":
    solution()