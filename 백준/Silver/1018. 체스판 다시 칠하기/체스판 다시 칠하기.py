import sys


#sys.stdin = open("input.txt", "rt")

N, M = map(int, sys.stdin.readline().rstrip().split())

trans_table = str.maketrans('WB', '10')
arr = [int(sys.stdin.readline().rstrip().translate(trans_table),2) for _ in range(N)]

WB_line = int('10' * 4, 2)
BW_line = int('01' * 4, 2)
correct_1 = [WB_line, BW_line] * 4
correct_2 = [BW_line, WB_line] * 4


def solution():
	answer = 64
	for i in range(N - 7):
		for j in range(M - 7):
			comp_1 = 0
			comp_2 = 0
			for k in range(8):
				test = (arr[i + k] >> (M - 8 - j)) & 255
				comp_1 += (correct_1[k] ^ test).bit_count()
				comp_2 += (correct_2[k] ^ test).bit_count()
			answer = min(comp_1, comp_2, answer)
				
	sys.stdout.write(str(answer) + '\n')
if __name__ == "__main__":
	solution()