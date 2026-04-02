import sys
import heapq

#sys.stdin = open("input.txt", "rt")

def solution():
    N, K = map(int, sys.stdin.readline().split())
    arr = list(map(int, sys.stdin.readline().split()))
    
    heap = []
    
    for i in range(K):
        heapq.heappush(heap, (arr[i], i))
    
    answer = heap[0][0]
    
    for i in range(K, N):
        heapq.heappush(heap, (arr[i], i))
        
        # 제일 작은 값의 index가 우리가 봐야하는 부분에서 나갔다면 pop
        while heap[0][1] < i - K + 1:
            heapq.heappop(heap)
        #기존 answer과 현재 최솟값 비교
        answer = max(answer, heap[0][0])
    
    
    sys.stdout.write(str(answer) + "\n")



if __name__ == "__main__":
    solution()