def solution(a, b):
    # 1. 2016년(윤년)의 각 월별 일수
    months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    # 2. 기준일(1월 1일)이 금요일이므로, 인덱스 0을 "FRI"로 설정
    days = ["FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"]
    
    # 3. 1월 1일부터 a월 b일까지 경과한 총 일수 계산
    # a월 이전까지의 월별 일수를 모두 더함 (인덱스 구조상 a-1까지 슬라이싱)
    total_passed_days = sum(months[:a-1]) + b - 1
    
    # 4. 경과 일수를 7로 나눈 나머지로 요일 찾기
    answer = days[total_passed_days % 7]
    
    return answer