def solution(n, computers):
    visited = [False] * n
    network = 0
    def dfs(node):
        visited[node] = True
        for i, nodes in enumerate(computers[node]):
            if not visited[i] and nodes == 1:
                dfs(i)
    
    for i in range(n):
        if not visited[i]:
            dfs(i)
            network += 1

    return network