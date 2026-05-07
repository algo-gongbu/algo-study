def solution(id_list, report, k):
    answer = [0] * len(id_list)
    report = set(report)
    report_dict = {}
    
    # 1. 신고 관계 저장
    for r in report:
        a, b = r.split()
        
        if b not in report_dict:
            report_dict[b] = set()
        
        report_dict[b].add(a)
    
    # 2. 이름 → 인덱스 매핑
    id_index = {}
    for i in range(len(id_list)):
        id_index[id_list[i]] = i
    
    # 3. 정지 처리 + 메일 카운트
    for user in report_dict:
        if len(report_dict[user]) >= k:
            for reporter in report_dict[user]:
                answer[id_index[reporter]] += 1
    
    return answer