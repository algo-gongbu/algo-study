import sys

#sys.stdin = open("input.txt", "rt")

def solution():
    X = int(sys.stdin.readline())
    
    dp = [0] * (X + 1)
    
    for i in range(2, X + 1):
        dp[i] = dp[i - 1] + 1
        
        # 2. 만약 2로 나누어 떨어지면, 1을 뺀 경우와 2로 나눈 경우 중 최솟값 갱신!
        if i % 2 == 0:
            dp[i] = min(dp[i//2] + 1, dp[i])
        if i % 3 == 0:
            dp[i] = min(dp[i//3] + 1, dp[i] )
            
            
    sys.stdout.write(str(dp[X]) + "\n")

if __name__ == "__main__":
    solution()