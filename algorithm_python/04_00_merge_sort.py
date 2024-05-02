# 합병 정렬

# best : O(nlogn)
# average : O(nlogn)
# worst : O(nlogn)

# divide and conquer
# 분할할때 logn = depth, 합칠때 비교 연산이 있으므로 n번, 따라서 nlogn

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


def merge_sort(l):
    # l의 길이가 2보다 작다면 l을 return(정렬 된것)
    if len(l) < 2:
        return l
    
    # 전체 길이의 절반으로 나눈다
    mid = len(l)//2
    left_l = l[:mid]
    right_l = l[mid:]

    # 나눈 부분 각각에 대해 재귀적으로 정렬 알고리즘 적용
    left_l = merge_sort(left_l)
    right_l = merge_sort(right_l)

    # 두 정렬된 배열 병합
    return merge(l,left_l,right_l)


def main():
    arr = [8,6,7,4,2,3,1,5]

    print(merge_sort(arr))
    return None

if __name__ == '__main__':
    main()