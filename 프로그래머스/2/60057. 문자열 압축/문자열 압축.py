def solution(s):
    answer = len(s)  # 초기값은 최대 길이
    count = 1

    for k in range(1, len(s)//2 + 1):
        prev = s[0:k]      # 이전 문자열
        count = 1
        compressed = ""

        for i in range(k, len(s), k):
            curr = s[i:i+k]   # 현재 문자열

            if prev == curr:
                count += 1
            else:
                if count > 1:
                    compressed += str(count)
                compressed += prev

                prev = curr
                count = 1

        # 마지막 처리
        if count > 1:
            compressed += str(count)
        compressed += prev

        # 최소 길이 갱신
        answer = min(answer, len(compressed))

    return answer