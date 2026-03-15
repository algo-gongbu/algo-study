import sys
import copy

def rotate_45(n, matrix):
    result = copy.deepcopy(matrix)
    mid = n // 2
    
    for i in range(n):
        result[i][mid] = matrix[i][i]
        result[i][n-1-i] = matrix[i][mid]
        result[mid][n-1-i] = matrix[i][n-1-i]
        result[i][i] = matrix[mid][i]
        
    return result

def solve():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n, d = map(int, sys.stdin.readline().split())
        matrix = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
        
        count = (d % 360) // 45
        
        for _ in range(count):
            matrix = rotate_45(n, matrix)
            
        for row in matrix:
            print(*(row))

solve()