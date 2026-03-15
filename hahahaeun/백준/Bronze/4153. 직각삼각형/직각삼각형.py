while True:
    num = list(map(int, input().split()))
    
    if all(x == 0 for x in num):
        break

    max_num = max(num)
    max_index = num.index(max_num)
    sum = 0

    for i in range(3):
        if i == max_index:
            continue

        else:
            sum += num[i] ** 2

    if max_num ** 2 == sum:
        print("right")

    else:
        print("wrong")