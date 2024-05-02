#알고리즘 2차 과제
import sys
import random

# quick sort
# Time Complexity - best : O(nlogn), worst : O(n^2)
# Space Complexity - best : O(logn), worst : O(n)
def quick_sort(l):
    if len(l) <= 1:
        return l
    pivot = l[len(l) // 2]
    left = [x for x in l if x < pivot]
    middle = [x for x in l if x == pivot]
    right = [x for x in l if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

# quick_sort_randomized
# Time Complexity - best : O(nlogn), worst : O(n^2) (less likely)
# Space Complexity - best : O(logn), worst : O(n)
def quick_sort_randomized(l):
    if len(l) <= 1:
        return l
    pivot = random.choice(l) 
    left = [x for x in l if x < pivot]
    middle = [x for x in l if x == pivot]
    right = [x for x in l if x > pivot]
    return quick_sort_randomized(left) + middle + quick_sort_randomized(right)

# quick_sort_tail_recursive
# Time Complexity - best : O(nlogn), worst : O(n^2)
# Space Complexity - best : O(logn), worst : O(logn)
def quick_sort_tail_recursive(l, start=0, end=None):
    if end is None:
        end = len(l) - 1
    while start < end:
        pivot_index = partition(l, start, end)
        quick_sort_tail_recursive(l, start, pivot_index - 1)
        start = pivot_index + 1
    return l

def partition(arr, start, end):
    pivot = arr[end]
    low = start - 1
    for i in range(start, end):
        if arr[i] <= pivot:
            low += 1
            arr[low], arr[i] = arr[i], arr[low]
    arr[low + 1], arr[end] = arr[end], arr[low + 1]
    return low + 1


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
    
    f.write(' '.join(list(map(str,quick_sort(unsorted_list)))) + '\n')
    f.write(' '.join(list(map(str,quick_sort_randomized(unsorted_list)))) + '\n')
    f.write(' '.join(list(map(str,quick_sort_tail_recursive(unsorted_list)))))

    f.close()
    return None

if __name__ == '__main__':
    main()