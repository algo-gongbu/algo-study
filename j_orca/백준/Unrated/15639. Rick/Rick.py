import sys

#sys.stdin = open("input.txt", "rt")

def solution():
    inputs = sys.stdin.readline().rstrip()
    
    rick_Meme = {'Give you up', 'Let you down', 'Run around and desert you', 'Make you cry', 'Say goodbye', 'Tell a lie and hurt you'}
    if inputs in rick_Meme:
        sys.stdout.write('NO\n')
    else:
        sys.stdout.write('YES\n')
        
if __name__ == "__main__":
    solution()