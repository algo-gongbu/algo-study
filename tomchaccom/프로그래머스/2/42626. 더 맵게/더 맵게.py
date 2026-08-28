import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    
    while True: 
        
        # heapq.heapify(scoville)
        
        if len(scoville) == 1 and scoville[0] < K:
            return -1
        
        if scoville[0] < K:
            one = heapq.heappop(scoville)
            two = heapq.heappop(scoville)
            
            new = one + 2 * two
            heapq.heappush(scoville, new)
            answer += 1
        else:
            break
    
    return answer

# print(solution([1, 2, 3, 9, 10, 12], 7))