def sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

def solution(array, commands):
    answer = []
    for com_set in commands:
        i,j,k = com_set
        temp = array[i-1:j]
        sort(temp)
        answer.append(temp[k-1])
    return answer