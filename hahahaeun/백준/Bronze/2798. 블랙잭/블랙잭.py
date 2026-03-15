n, m = map(int, input().split())

num = list(map(int, input().split()))
num.sort()
card = []

mini = m
for i in range(n):
    for j in range(1, n):
        for f in range(2, n):
            if i != j and j != f and i != f:
                if m - num[i] - num[j] - num[f] < mini and m - num[i] - num[j] - num[f] >= 0:
                    mini = m - num[i] - num[j] - num[f]
                    card.append([num[i], num[j], num[f]])
                    

else:
    print(sum(card[len(card)-1]))
    