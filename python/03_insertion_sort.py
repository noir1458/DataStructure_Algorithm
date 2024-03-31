# 삽입 정렬

# best : O(n)
# average : O(n^2)
# worst : O(n^2)

# 카드를 정렬하는 것처럼 반복적으로 key를 정렬안된 부분에서 정렬된 부분으로 옮긴다. key는 두번째부터

l = [7,4,3,6,8,1,2]

for i in range(1,len(l)):
    key = l[i]
    # key는 두번째부터, 인덱스가 가리키는 값을

    # 정렬된 부분은 key 앞 부분이다
    j = i - 1 # j는 정렬된 부분의 시작점

    while j >= 0 and l[j] > key: # l[j]가 key보다 작거나 같을때 작동
        l[j + 1] = l[j] #j+1 자리에 j 내용을 넣고
        j = j - 1
    l[j + 1] = key # l[i] 가 key보다 작다면 l[i+1]에 key 내용을 넣어서 정렬


print(l)