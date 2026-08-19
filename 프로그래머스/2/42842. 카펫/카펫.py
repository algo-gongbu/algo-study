def solution(brown, yellow):
    answer = []
    by = [] 
    
    # 넓이를 먼저 구함
    area = brown + yellow
    
    # brown , yellow가 가능한 튜플 검색 
    for i in range(1,area+1):
        if i * i > area:
            break
        if area % i == 0:
            by.append((i, area // i))
        

    
    # 실제 사각형을 이차원 배열로 만들어서 카운트 0, w-1, h-1은 brown임 
    # 1또는 2는 yel 가 0이 되어서 안됨
    by = [case for case in by if not(
        case[1] == 1 or 
        case[0] == 1 or 
        case[1] == 2 or 
        case[0] == 2)] 
    
    print(by)
    
    brown_count = 0
    yel_count = 0
    
    if len(by) == 1:
        w = max(by[0])
        h = min(by[0])
        answer.append(w)
        answer.append(h)
        return answer
    
    for case in by:
        w = max(case)
        h = min(case)
        
        # print("case" , w)
        # print("case" , h)
        
        # 0 이 2차원 배열을 만들지 말고, 카운트를 비교  
        if (w * 2 + (h-2) * 2) == brown and (area - brown) == yellow:
            answer.append(w)
            answer.append(h)
            break
            
    
    
    return answer
