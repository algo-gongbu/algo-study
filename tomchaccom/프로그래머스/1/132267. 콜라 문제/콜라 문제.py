def solution(a, b, n):
    answer = 0
    
    # 가지고 있는 빈 병(n)이 마트에 주어야 하는 병(a)보다 크거나 같을 때만 교환 가능
    while n >= a:
        # 이번에 마트에서 새로 받을 수 있는 콜라의 병 수
        new_bottles = (n // a) * b
        answer += new_bottles
        
        # 다음 턴을 위한 빈 병 계산 = 새로 받은 병 + 묶음에 포함되지 않고 남은 병
        n = new_bottles + (n % a)
        
    return answer