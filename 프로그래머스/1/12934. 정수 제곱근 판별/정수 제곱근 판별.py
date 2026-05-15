import math

def solution(n):
    root = math.sqrt(n)

    # 제곱근이 정수인지 확인
    if root % 1 != 0:
        return -1
    else:
        return int(math.pow(root + 1, 2))