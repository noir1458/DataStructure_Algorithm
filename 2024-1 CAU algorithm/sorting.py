#알고리즘 1차 과제
import sys

# 삽입 정렬
# best : O(n)
# average : O(n^2)
# worst : O(n^2)
# 카드를 정렬하는 것처럼 반복적으로 key를 정렬안된 부분에서 정렬된 부분으로 옮긴다. key는 두번째부터
def Insertion_sort(l):
    for key_idx in range(1,len(l)):
        key = l[key_idx]
        idx = key_idx-1
        while idx >= 0 and l[idx] > key:
            l[idx + 1] = l[idx]
            idx -= 1
        l[idx+1] = key
    return l

# merge
# merge_sort 에서 merge 부분 구현한 함수
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

# 합병 정렬
# best : O(nlogn)
# average : O(nlogn)
# worst : O(nlogn)
def Merge_sort(l):
    # l의 길이가 2보다 작다면 l을 return(정렬 된것)
    if len(l) < 2:
        return l
    
    # 전체 길이의 절반으로 나눈다
    mid = len(l)//2
    left_l = l[:mid]
    right_l = l[mid:]

    # 나눈 부분 각각에 대해 재귀적으로 정렬 알고리즘 적용
    left_l = Merge_sort(left_l)
    right_l = Merge_sort(right_l)

    # 두 정렬된 배열 병합
    return merge(l,left_l,right_l)


# merge_insertion sort

# sort (subarray of size K 로 분할)
# best : O(K * (n/K)) = O(n)
# worst : O(K^2 * (n/K)) = O(nK)
# N은 원본 배열의 크기, n/K 는 subarray의 숫자

# merge (for the n/K sorted subarrays)
# the number of levels * the cost of merging at each level = log(n/k) * O(N) = O(n log(n/K))

# 배열이 클때는 merge_sort, 작을때는 insertion_sort 사용하여 정렬
def Merge_and_insertion_sort(arr,n):
    if len(arr) > n: # 크기는 n을 기준으로 한다
        Merge_sort(arr)
    else:
        Insertion_sort(arr)
    return arr



def main():
    # argc : the number of arguments
    # argv : argument vectors
    
    input = open(sys.argv[1],'r')
    output = open(sys.argv[2],'w')
    length = int(input.readline())
    
    #print(length)
    input1 = list(input)
    unsorted_list = list(map(int,input1[0].split()))
    #print(unsorted_list)

    # 파일 쓰기
    f = open('./output.txt','w')
    f.write(' '.join(list(map(str,Insertion_sort(unsorted_list)))) + '\n')
    f.write(' '.join(list(map(str,Merge_sort(unsorted_list)))) + '\n')
    n=3
    f.write(' '.join(list(map(str,Merge_and_insertion_sort(unsorted_list,n)))))
    f.close()
    return None

if __name__ == '__main__':
    main()