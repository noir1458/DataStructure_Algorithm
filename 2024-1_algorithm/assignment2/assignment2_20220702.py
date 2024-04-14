#알고리즘 2차 과제
import sys


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
    '''
    f.write(' '.join(list(map(str,Insertion_sort(unsorted_list)))) + '\n')
    f.write(' '.join(list(map(str,Merge_sort(unsorted_list)))) + '\n')
    n=3
    f.write(' '.join(list(map(str,Merge_and_insertion_sort(unsorted_list,n)))))
'''
    f.close()
    return None

if __name__ == '__main__':
    main()