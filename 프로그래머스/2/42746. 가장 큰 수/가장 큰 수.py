# Bubble sort -> O(N^2) -> 시간 복잡도 문제
# Merge Sort O(NlogN) 사용. 

def compare(x, y):
    if x + y > y + x:
        return -1
    elif x + y < y + x:
        return 1
    else:
        return 0

def merge_sort(arr):
        if len(arr) <= 1:
            return arr

        mid = len(arr) // 2
        left_half = merge_sort(arr[:mid])
        right_half = merge_sort(arr[mid:])

        return merge(left_half, right_half)

def merge(left, right):
        result = []
        i = j = 0

        while i < len(left) and j < len(right):
            com_l, com_r = str(left[i]), str(right[j])
            if compare(com_l,com_r) == -1:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1

        result.extend(left[i:])
        result.extend(right[j:])
        return result


def solution(numbers):
    n = len(numbers)
    fin = merge_sort(numbers)
    
    answer = ''
    for i in range(n): answer += str(fin[i])
    if answer[0] == "0":
        return "0"
    else: 
        return answer