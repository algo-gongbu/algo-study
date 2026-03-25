import sys

input = sys.stdin.readline

n = int(input())
m = int(input())

s = input().strip()

pattern_count = 0
pn_count = 0
i = 0

while i < m-2:
    if s[i:i+3] == 'IOI':
        pattern_count += 1

        if pattern_count == n:
            pn_count += 1
            pattern_count -= 1

        i += 2

    else:
        pattern_count = 0
        i += 1

print(pn_count)