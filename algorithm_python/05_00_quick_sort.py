# 퀵 정렬

# best : O()
# average : O()
# worst : O()


def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

# 테스트
arr = [3, 6, 8, 10, 1, 2, 1]
print("정렬 전:", arr)
print("정렬 후:", quick_sort(arr))