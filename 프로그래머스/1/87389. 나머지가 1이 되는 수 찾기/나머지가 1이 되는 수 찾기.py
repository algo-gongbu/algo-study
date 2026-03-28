def solution(n):
    number = []
    for x in range(2,n):
        if (n % x) == 1:
            number.append(x)
    answer = number[0]
    return answer