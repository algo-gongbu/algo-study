def solution(s):
    answer = 0

    x = ''
    same = 0
    diff = 0

    for c in s:

        # 새로운 문자열 시작
        if x == '':
            x = c

        # 개수 세기
        if c == x:
            same += 1
        else:
            diff += 1

        # 같아지면 분리
        if same == diff:
            answer += 1

            x = ''
            same = 0
            diff = 0

    # 남은 문자열 처리
    if x != '':
        answer += 1

    return answer