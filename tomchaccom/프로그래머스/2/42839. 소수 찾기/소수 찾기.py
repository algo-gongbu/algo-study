from itertools import permutations

def isPrime(num):
    if num < 2:
        return False
    i = 2
    
    while i * i <= num:
        if num % i == 0:
            return False
        i += 1
        
    return True

def solution(numbers):
    answer = 0
    validate = []
    
    # 조합할 숫자를 저장하기 
    for l in range(1, len(numbers)+1):
        for case in permutations(numbers, l):
            ca = int("".join(case))
            validate.append(ca)
    
    validate = set(validate)
    #print(validate)
    # 소수 판정 함수로 필터링 컨프리헨션 
    val = [v for v in validate if isPrime(v)]
    # print(val)

    val2 = set(val)
    return len(val2)
    