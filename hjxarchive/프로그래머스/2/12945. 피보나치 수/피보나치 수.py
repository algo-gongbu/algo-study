def solution(n):
    sol = [0,1]
    if len(sol) <= n+1:
        while len(sol) != n+1:
            sol.append(sol[-1]+sol[-2])
    answer = sol[n] % 1234567
    return answer