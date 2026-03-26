import sys


#sys.stdin = open("input.txt", "rt")

def solution():
	N, M = map(int, sys.stdin.readline().rstrip().split())

	cannot_heardSet = {sys.stdin.readline().rstrip() for _ in range(N)} # sys.stdin.readline().rstrip()은 문자열(String)을 반환
	cannot_seeSet = {sys.stdin.readline().rstrip() for _ in range(M)}
	
	inner_Section = sorted(cannot_heardSet & cannot_seeSet) #sorted() 함수는 순회 가능한(Iterable) 어떤 객체가 들어오든 항상 깔끔하게 정렬된 '리스트(List)'를 반환
	
	sys.stdout.write(str(len(inner_Section)) + "\n" + "\n".join(inner_Section) + "\n")
		
if __name__ == "__main__":
	solution()