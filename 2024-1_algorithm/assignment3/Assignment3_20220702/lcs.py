import sys

# computing maximum length of a common subsequence
# between two sequences and finding the LCS itself
def LCS(seq_A,seq_B):
    #LCS를 찾는다
    a = len(seq_A) + 1
    b = len(seq_B) + 1
    lcs = [['-' for _ in range(a)] for _ in range(b)]

    for i in range(a):
        for j in range(b):
            if (i == 0 or j == 0):
                lcs[i][j] = 0
            elif (seq_A[i-1] == seq_B[j-1]):
                lcs[i][j] = lcs[i-1][j-1] + 1
            else:
                lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j])

    length = lcs[-1][-1]
    LCS_str = LCS_print(seq_A,seq_B,lcs)
    return LCS_str, length

# function for printing the LCS and its length
def LCS_print(seq_A,seq_B,lcs):
    # LCS와 길이 print
    i = len(seq_A)
    j = len(seq_B)
    LCS_word = []
    while (i != 0 and j != 0):
        if(seq_A[i-1] == seq_B[j-1]):
            LCS_word.append(seq_A[i-1])
            i -= 1
            j -= 1
        else: # 같지 않은 경우 위나 왼쪽값중 큰 수로 이동, 등호가 없다면 왼쪽
            if lcs[i-1][j] > lcs[i][j-1]:
                i -= 1
            else:
                j -= 1
    return ''.join(LCS_word[::-1])

# function for finding the most similar sequence of a given sequence
def find_most_similar_sequence(n_seq, target_seq_index):
    # 가장 유사도가 높은 seq를 찾는다 주어진 seq들 중
    # 가장 유사한것 idx와, lcs_word와, 길이 return
    most_similar_seq = ''
    seq_len = 0
    similar_index = 0

    for i in range(len(n_seq)):
        if i == target_seq_index:
            continue
        tmp_seq,tmp_len = LCS(n_seq[target_seq_index],n_seq[i])
        if seq_len < tmp_len:
            seq_len = tmp_len
            most_similar_seq = tmp_seq
            similar_index = i
    return most_similar_seq, seq_len, similar_index + 1


def main():
    # argc : the number of arguments
    # argv : argument vectors
    input = open(sys.argv[1],'r')
    output = open(sys.argv[2],'w')
    length = int(input.readline().strip())
    
    #print(length)
    sequence_list = list(input)
    sequence_list = list(map(lambda x:x.rstrip(),sequence_list))
    #print(sequence_list)

    # 출력
    # k번째 줄은 k번째 seq의 가장 유사한 seq정보
    # 가장 유사한것 idx _ lcs길이 _ lcs

    # 파일 쓰기
    f = open('./output.txt','w')
    
    for i in range(len(sequence_list)):
        result = find_most_similar_sequence(sequence_list,i)
        f.write(str(result[2]) + '\t' + str(result[1]) + '\t' + result[0])
        if i != len(sequence_list)-1:
            f.write('\n')

    f.close()
    return None

if __name__ =='__main__':
    main()