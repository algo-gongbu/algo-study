import sys

def solve():
    h, w = map(int, sys.stdin.readline().split())

    blocks = list(map(int, sys.stdin.readline().split()))
    
    total_water = 0
    
    for i in range(1, w - 1):
        left_max = max(blocks[:i])
        
        right_max = max(blocks[i+1:])
        
        compare_height = min(left_max, right_max)
        
        if compare_height > blocks[i]:
            total_water += compare_height - blocks[i]
            
    print(total_water)

solve()