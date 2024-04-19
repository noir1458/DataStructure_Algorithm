import random

def randomized_quick_sort(arr):
    if len(arr) <= 1:
        return arr
    
    pivot = random.choice(arr)  # 리스트 내에서 무작위로 피벗 선택
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    
    return randomized_quick_sort(left) + middle + randomized_quick_sort(right)

# 테스트
arr = [3, 6, 8, 10, 1, 2, 1]
print("정렬 전:", arr)
print("정렬 후:", randomized_quick_sort(arr))