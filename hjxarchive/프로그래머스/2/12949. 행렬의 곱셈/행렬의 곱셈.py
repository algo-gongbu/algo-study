def solution(arr1, arr2):
    h = len(arr1)
    w = len(arr2[0])
    r = len(arr2)
    answer = [[0] * w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            for k in range(r):
                answer[i][j] += arr1[i][k]*arr2[k][j]
    return answer