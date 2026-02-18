def get_length(s1, s2):
    count = 0
    
    for j in range(min(len(s1), len(s2))):
        if s1[j] == s2[j]:
            count += 1
        else:
            break
    return count

import sys
N = int(sys.stdin.readline())
word = []

for i in range(N):
    s = sys.stdin.readline().strip()
    word.append((s,i))

original_word = [s[0] for s in word]
word.sort()

max_len = -1
candidates = set()
for i in range(N - 1):
    length = get_length(word[i][0], word[i+1][0])
    if length > max_len:
        max_len = length
        candidates = {word[i][1], word[i+1][1]}
    elif length == max_len and length != -1:
        candidates.add(word[i][1])
        candidates.add(word[i+1][1])
for i in range(N):
    if i not in candidates:
        continue
    
    for j in range(i + 1, N):
        if j in candidates:
            if get_length(original_word[i], original_word[j]) == max_len:
                print(original_word[i])
                print(original_word[j])
                sys.exit()