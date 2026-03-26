import sys


#sys.stdin = open("input.txt", "rt")

def solution():
	N, M = map(int, sys.stdin.readline().rstrip().split())

	pocketmon_table = {}
	for num in range(1,N+1):
		pocketmon_table[str(sys.stdin.readline().rstrip())] = num
		
	pocketmon_list = list(pocketmon_table.keys())
	for _ in range(M):
		question = sys.stdin.readline().rstrip()
		if question.isdigit() :
			sys.stdout.write(pocketmon_list[int(question) - 1] + "\n")
		else:
			sys.stdout.write(str(pocketmon_table[question]) + "\n")
			
		
if __name__ == "__main__":
	solution()