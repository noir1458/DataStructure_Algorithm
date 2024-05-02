# 선택 정렬

# best : O(n^2)
# average : O(n^2)
# worst : O(n^2)

# 최대나 최소인 데이터를 찾아 선택하는 방법

# 오름차순 - 최소, 내림차순 - 최대 를 찾고
# 가장 앞의 데이터와 swap

l = [7,4,3,6,8,1,2]

for i in range(len(l)):
    min = i                         # 처음 i 를 min으로 잡고
    for j in range(i+1,len(l)):     # i+1 부터 min값을 찾는다.
        if l[min] > l[j]:
            min = j                 #가장 작은값 인덱스를 min에
    l[i] , l[min] = l[min], l[i]    #인덱스 min과 i의 값 바꾸기
print(l)