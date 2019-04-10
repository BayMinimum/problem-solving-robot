import sys

Q = ['0'*8 + '1'*8, ('0'*4 + '1'*4)*2, ('0'*2 + '1'*2)*4, '01'*8]
C = [''.join([Q[j][i] for j in range(4)]) for i in range(16)]

T = int(input())

for case in range(1, T+1):
    N, B, F = [int(x) for x in input().split()]
    n = (N+15) // 16
    S = ''
    for i in range(n):
        S += ('0' if i%2 == 0 else '1') * 16
    print(S[:N])
    sys.stdout.flush()
    R = input()
    remain = []
    char = '0'
    cnt = 0
    for r in R:
        if r == char:
            cnt += 1
        else:
            char = r
            remain.append(cnt)
            cnt = 1
    if cnt:
        remain.append(cnt)
    L = []
    for q in Q:
        print((q*n)[:N])
        sys.stdout.flush()
        L.append(input())
    ret = []
    cur = 0
    for k in range(len(remain)):
        R = [''.join([L[j][i] for j in range(4)]) for i in range(cur, cur + remain[k])]
        for i in range(16 if k < n-1 else (N-1) % 16 + 1):
            if C[i] not in R:
                ret.append(str(k*16 + i))
        cur += remain[k]
    print(' '.join(ret))
    sys.stdout.flush()
    input()