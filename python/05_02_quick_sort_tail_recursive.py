def quick_sort_tail_recursive(arr, start=0, end=None):
    if end is None:
        end = len(arr) - 1

    if start >= end:
        return arr

    pivot_index = partition(arr, start, end)
    quick_sort_tail_recursive(arr, start, pivot_index - 1)
    start = pivot_index + 1
    # 재귀 호출을 꼬리 재귀로 변경
    return quick_sort_tail_recursive(arr, start, end)

def partition(arr, start, end):
    pivot = arr[end]
    low = start - 1
    for i in range(start, end):
        if arr[i] <= pivot:
            low += 1
            arr[low], arr[i] = arr[i], arr[low]
    arr[low + 1], arr[end] = arr[end], arr[low + 1]
    return low + 1

# 테스트
arr = [3, 6, 8, 10, 1, 2, 1]
print("정렬 전:", arr)
print("정렬 후:", quick_sort_tail_recursive(arr))