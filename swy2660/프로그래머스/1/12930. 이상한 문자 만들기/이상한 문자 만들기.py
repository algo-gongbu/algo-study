def solution(s):
    answer = ''
    word_index = 0   # 단어 내 인덱스

    for i in range(len(s)):
        if s[i] == ' ':
            answer += ' '
            word_index = 0   # 공백 만나면 초기화
        else:
            if word_index % 2 == 0:
                answer += s[i].upper()
            else:
                answer += s[i].lower()
            
            word_index += 1

    return answer