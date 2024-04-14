def counting_sort(l):
    max_val = max(l)
    counts = [0 for _ in range(max_val + 1)]
    sorted_arr = [0 for _ in range(len(l))]

    for num in l:
        counts[num] += 1
    
    for i in range(1,len(counts)):
        counts[i] = counts [i-1]
    
    for num in l[::-1]:
        sorted_arr[counts[num]-1] = num
        counts[num] -= 1

    return sorted_arr