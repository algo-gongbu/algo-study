def compare(x, y):
    if x>y:
        return -1
    elif x<y:
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
            if compare(left[i],right[j]) == -1:
                result.append(left[i])
                i += 1
            else:
                result.append(right[j])
                j += 1

        result.extend(left[i:])
        result.extend(right[j:])
        return result

def solution(citations):
    sorted = merge_sort(citations)
    for i in range(len(citations)):
        if sorted[i] < i + 1:
                return i
    return len(citations)