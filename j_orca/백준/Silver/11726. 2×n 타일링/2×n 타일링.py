import sys
import math
#sys.stdin = open("input.txt", "rt")

def solution():
    N = int(sys.stdin.readline().rstrip())
    answer = 0
    
    # Column 기준으로 평가
    for r in range(math.floor(N/2) + 1): # 1*2가 차지하는 수 0 ~ 전체
        N_real = N - 2 * r 
        # 종류도 그떄 그때 달라짐 2*1 즉, 총 N_real 자리 중, r의 자리를 선택해야하는 문제 그리고 각각의 순서가 상관 없음.
        # 또는 종류로 순열처럼 생각하고 2*1과 1*2의 순서가 상관없기에 이를 계산
        answer += int(math.factorial(r + N_real) // (math.factorial(r) * math.factorial(N_real)))
        #/를 사용하면 float의 IEEE로 인한 오류 누적 15 ~ 17자리만 정확
        
    answer = answer % 10007
    
    sys.stdout.write(str(answer) + '\n')
    
if __name__ == "__main__":
    solution()