def solution(n, m):

    a, b = n, m

    # 최대공약수
    while b != 0:
        a, b = b, a % b

    gcd = a

    # 최소공배수
    lcm = n * m // gcd

    return [gcd, lcm]