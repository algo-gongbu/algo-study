visited = [False] * 1000
subtree_size = [0] * 1000


def solution(n, wires):
    answer = []
    graph = [[] for _ in range(n+1)]
    
    
    for v1, v2 in wires:
        graph[v1].append(v2)
        graph[v2].append(v1)
    
    dfs(graph, 1)
    for i in range(1, n + 1):
        answer.append(abs(n - 2 * subtree_size[i]))
    
    return min(answer)


def dfs(graph, x):
    count = 1
    
    visited[x] = True
    
    for node in graph[x]:
        if not visited[node]:
            visited[node] = True
            count += dfs(graph, node)
    
    subtree_size[x] = count
    return count 



