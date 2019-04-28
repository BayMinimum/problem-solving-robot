def solve(Q, U, D):
    C = [0]
    for u in U:
        if u < Q:
            C.append(u+1)
    for d in D:
        if d > 0:
            C.append(d-1)
    C.sort()
    ret, pop = 0, 0
    for c in C:
        p = 0
        for u in U:
            if u < c:
                p += 1
        for d in D:
            if d > c:
                p += 1
        if p > pop:
            ret, pop = c, p
    return ret    

T = int(input())
for case in range(1, T+1):
    P, Q = [int(x) for x in input().split()]
    Xu, Xd, Yu, Yd = [], [], [], []
    for i in range(P):
        I = input().split()
        x, y = int(I[0]), int(I[1])
        if I[2] == 'N':
            Yu.append(y)
        elif I[2] == 'S':
            Yd.append(y)
        elif I[2] == 'E':
            Xu.append(x)
        else:
            Xd.append(x)
    x = solve(Q, Xu, Xd)
    y = solve(Q, Yu, Yd)
    print('Case #{}: {} {}'.format(case, x, y))