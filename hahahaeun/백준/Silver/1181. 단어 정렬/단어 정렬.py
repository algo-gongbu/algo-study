n = int(input())
word = []
for _ in range(n):
    w = input()
    word.append(w)


sorted_word = sorted(set(word))

sorted_word.sort(key = lambda x: (len(x), x))

for i in sorted_word:
    print(i)