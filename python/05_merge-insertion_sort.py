# merge_insertion sort

# sort (subarray of size K 로 분할)
# best : O(K * (n/K)) = O(n)
# worst : O(K^2 * (n/K)) = O(nK)
# N은 원본 배열의 크기, n/K 는 subarray의 숫자

# merge (for the n/K sorted subarrays)
# the number of levels * the cost of merging at each level = log(n/k) * O(N) = O(n log(n/K))

# 배열이 클때는 merge_sort, 작을때는 insertion_sort 사용하여 정렬

'''
Merge-Insertion Sort는 Merge Sort와 Insertion Sort를 결합한 정렬 알고리즘입니다. 이 알고리즘은 일반적인 Merge Sort와는 달리 작은 크기의 부분 배열에 대해서는 Insertion Sort를 사용하여 성능을 향상시킵니다.

일반적으로 Merge Sort는 대규모 배열을 효율적으로 정렬하는 데에 탁월한 성능을 보이지만, 배열의 크기가 작을 때에는 Insertion Sort가 더 효율적일 수 있습니다. Merge-Insertion Sort는 이러한 특성을 고려하여 배열의 크기에 따라 Merge Sort와 Insertion Sort를 적절히 선택하여 정렬을 수행합니다.

Merge-Insertion Sort의 주요 특징은 다음과 같습니다:

작은 크기의 배열에 대한 삽입 정렬 사용: 정렬할 배열의 크기가 일정 기준 값 이하일 때에는 Insertion Sort를 사용하여 정렬합니다. Insertion Sort는 작은 크기의 배열에 대해서는 빠르게 동작하는 특성이 있으므로, 이를 활용하여 성능을 향상시킵니다.

분할 정복(Divide and Conquer) 방식의 Merge Sort 사용: 배열을 두 개의 부분 배열로 분할하고, 각 부분 배열을 재귀적으로 정렬한 후 병합하는 Merge Sort의 방식을 따릅니다. 이를 통해 배열을 더 작은 단위로 분할하고 정렬하여 최종적으로 전체 배열을 정렬합니다.

Merge-Insertion Sort는 작은 크기의 배열에 대해서는 Insertion Sort를 사용하여 삽입 정렬의 이점을 살리고, 대규모 배열에 대해서는 Merge Sort를 사용하여 분할 정복의 장점을 살립니다. 이를 통해 정렬 속도를 향상시키고 효율적으로 정렬을 수행할 수 있습니다.
'''
def Insertion_sort(l):
    for key_idx in range(1,len(l)):
        key = l[key_idx]
        idx = key_idx-1
        while idx >= 0 and l[idx] > key:
            l[idx + 1] = l[idx]
            idx -= 1
        l[idx+1] = key
    return l

def merge(l,left,right):
    left_idx = right_idx = l_idx = 0 # 배열 인덱스 초기화

    # 좌우 배열 비교하여 병합
    while left_idx < len(left) and right_idx < len(right):
        if left[left_idx] < right[right_idx]:
            l[l_idx] = left[left_idx]
            left_idx+=1
        else:
            l[l_idx] = right[right_idx]
            right_idx +=1
        l_idx += 1

    # 왼쪽 배열 남은경우 병합
    while left_idx < len(left):
        l[l_idx] = left[left_idx]
        left_idx += 1
        l_idx += 1

    # 오른쪽 배열이 남은 경우 병합
    while right_idx < len(right):
        l[l_idx] = right[right_idx]
        right_idx += 1
        l_idx += 1
    
    return l


def Merge_sort(l):
    # l의 길이가 2보다 작다면 l을 return(정렬 된것)
    if len(l) < 2:
        return l
    
    # 전체 길이의 절반으로 나눈다
    mid = len(l)//2
    left_l = l[:mid]
    right_l = l[mid:]

    # 나눈 부분 각각에 대해 재귀적으로 정렬 알고리즘 적용
    Merge_sort(left_l)
    Merge_sort(right_l)

    # 두 정렬된 배열 병합
    return merge(l,left_l,right_l)

def MergeInsertionSort(arr,n):
    if len(arr) > n:
        Merge_sort(arr)
    else:
        Insertion_sort(arr)
    return arr

def main():
    l = [5,2,4,7,1,3,8,6]
    #print(InsertionSort(l))
    n=3
    print(MergeInsertionSort(l,n))
    return None

if __name__ == '__main__':
    main()