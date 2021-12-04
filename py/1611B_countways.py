def countways(a,b):
    if a > b:
       return countways(b,a)
    if b > 3*a:
        return a
    else:
        d = b - a
        count = d // 2
        a -= count
        b -= count*3
        count += (a+b)//4
        return count

N_INP = int(input())
inps = []
for i in range(N_INP):
    inps.append([int(k) for k in input().split(' ')])
for inp in inps:
    print(countways(*inp))