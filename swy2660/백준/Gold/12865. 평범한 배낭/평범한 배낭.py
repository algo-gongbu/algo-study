import sys
input = sys.stdin.readline

N, K = map(int, input().split())
dp = [0] * (K + 1)

for i in range(N):
    W, V = map(int, input().split())
    for w in range(K, W - 1, -1):
        dp[w] = max(dp[w], dp[w - W] + V)
    
print(dp[K])
# retry upload
