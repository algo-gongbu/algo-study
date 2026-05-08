def solution(n, words):
    answer = []
    word = [words[0]]
    for i in range(1, len(words)):
        if (words[i-1])[-1] != (words[i])[0] or words[i] in word:
            count = i + 1
            if count%n == 0:
                answer.append(count%n+n)
            else:
                answer.append(count%n)
            if count/n > count//n:
                answer.append(count//n+1)
            else:
                answer.append(count//n)
            return answer
        
        elif words[i] not in word:
            word.append(words[i])

    return [0,0]