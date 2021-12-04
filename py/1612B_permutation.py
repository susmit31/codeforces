def make_perm(n, a, b):
    nums = list(range(1,n+1))
    lt_arr = []
    in_left = {num:0 for num in nums}
    rt_arr = []
    in_right = {num:0 for num in nums}
    for num in nums:
        if len(lt_arr)==n/2 or len(rt_arr)==n/2:
            break
        if num < min(a,b):
            rt_arr.append(num)
            in_right[num] = 1
        elif num > max(a,b):
            lt_arr.append(num)
            in_left[num] = 1
    if len(lt_arr) < n/2:
        for num in nums:
            if in_right[num] == 0 and in_left[num] == 0 and num >= a and num != b:
                lt_arr.append(num)
                in_left[num] = 1
                if len(lt_arr)==n/2: break
    if len(rt_arr) < n/2:
        for num in nums:
            if in_left[num] == 0 and in_right[num] == 0 and num <= b and num != a:
                rt_arr.append(num)
                in_right[num] = 1
                if len(rt_arr)==n/2: break
            
    if len(lt_arr) != n/2 or len(rt_arr) != n/2:
        return -1
    return " ".join([str(k) for k in lt_arr + rt_arr])


NUM_TESTS = int(input())
for i in range(NUM_TESTS):
    [n, a, b] = [int(k) for k in input().split(" ")]
    print(make_perm(n,a,b))
