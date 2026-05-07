def solution(numbers, target):
    def dfs(idx, current_sum):
        # 모든 숫자를 다 사용했을 때
        if idx == len(numbers):
            # 타겟과 같으면 1가지 경우로 카운트
            return 1 if current_sum == target else 0

        # 현재 숫자를 + 또는 -로 사용하는 두 경우를 더해서 반환
        return dfs(idx + 1, current_sum + numbers[idx]) + dfs(idx + 1, current_sum - numbers[idx])
    
    # dfs(0, 0)에서 시작
    return dfs(0, 0)