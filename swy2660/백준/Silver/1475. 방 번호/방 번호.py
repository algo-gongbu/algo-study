import sys
input = sys.stdin.readline

N = int(input())

digit_count = [0] * 10
for digit in str(N):
    digit_count[int(digit)] += 1

digit_count[6] = (digit_count[6] + digit_count[9] + 1) // 2
digit_count[9] = 0

print(max(digit_count))