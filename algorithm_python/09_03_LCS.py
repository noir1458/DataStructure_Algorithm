
def LCS(X,Y):
    m = len(X) + 1
    n = len(Y) + 1
    result = [['-' for _ in range(n)] for _ in range(m)]

    for i in range(m):
        for j in range(n):
            if (i==0 or j==0):
                result[i][j] = 0
            elif (X[i-1] == Y[j-1]):
                result[i][j] = result[i-1][j-1] + 1
            else:
                result[i][j] = max(result[i][j-1],result[i-1][j])
            print(f"{result[i][j]:<3d}", end=' ')

        print()
    print()
    print('LCS number of two sequences is', result[-1][-1])
    return result

def print_LCS(X,Y,result):
    i = len(X)
    j = len(Y)
    LCS_word = []
    # 배열의 맨 마지막부터 시작해서 i=0,j=0까지 반복한다.
    while(i != 0 and j != 0):
        # 두 문자가 같을때만 LCS_word에 저장한 후 좌측 위로 이동
        if (X[i-1] == Y[j-1]):
            LCS_word.append(X[i-1])
            i=i-1
            j=j-1
        else: # 같지 않은경우 위나 왼쪽값중 큰수로 이동, 이 코드는 같다면 위로(결과 달라질수 있다)
            if result[i-1][j] >= result[i][j-1]:
                i = i-1
            else:
                j = j-1

    return LCS_word[::-1]


X = list('ABCBDA')
Y = list('BDCAB')
LCS(X,Y)
print(print_LCS(X,Y,LCS(X,Y)))