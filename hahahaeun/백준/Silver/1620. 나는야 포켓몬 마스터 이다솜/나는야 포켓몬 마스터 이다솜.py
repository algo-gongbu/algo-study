import sys

input = sys.stdin.readline

n, m = map(int, input().split())

pokemon = {}
pokemon2 = {}

for i in range(1, n+1):
    v = input().strip()

    pokemon[i] = v
    pokemon2[v] = i

for _ in range(m):
    target = input().strip()

    if target.isdigit():
        print(pokemon[int(target)])

    else:
        print(pokemon2[target])