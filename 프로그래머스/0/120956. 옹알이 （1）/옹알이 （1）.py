def solution(babbling):
    answer = 0
    word = ["aya", "ye", "woo", "ma"]
    
    for i in babbling:
        current = i
        for j in word:
            if j in i:
                current = current.replace(j, " ")

        
        if not current.strip():
            answer += 1
    
    return answer