import sys
T = int(sys.stdin.readline())

for _ in range(T):
    alpha_pos = {}
    W = sys.stdin.readline().strip()
    K = int(sys.stdin.readline())
    min_len = float('inf')
    max_len = -1
    
    for i, char in enumerate(W):
        if char not in alpha_pos:
            alpha_pos[char] = []
        alpha_pos[char].append(i)
    
    for char in alpha_pos:
        lst = alpha_pos[char]
        
        if len(lst) >= K:
            for j in range(len(lst)-K+1):
                distance = lst[j+K-1] - lst[j] + 1
                
                if distance <= min_len:
                    min_len = distance
                if distance >= max_len:
                    max_len = distance
    
    if max_len == -1:
        print(-1)
    else:
        print(min_len, max_len)