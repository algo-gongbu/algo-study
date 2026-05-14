def solution(s):
    word = list(map(int, s.split()))
    a = min(word)
    b = max(word)
    answer = f'{a} {b}' 
    return answer