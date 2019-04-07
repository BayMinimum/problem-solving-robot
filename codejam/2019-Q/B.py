T = int(input())
for case in range(1, T+1):
    N = int(input())
    _P = input()
    P = [0] * (2*N - 1)
    for i in range(2*N-2):
        P[i+1] = P[i] + (1 if _P[i] == 'S' else 0)
    D = [[False]*N for i in range(N)]
    D[0][0] = True
    if P[1] == 1:
        for j in range(1, N):
            D[0][j] = True
    for i in range(1, N):
        D[i][0] = (P[i] != i) and D[i-1][0]
        for j in range(1, N):
            D[i][j] = ((P[i+j] != i or P[i+j-1] != i) and D[i][j-1]) or ((P[i+j] != i or P[i+j-1] != i-1) and D[i-1][j])
    path = ''
    i, j = N-1, N-1
    while i + j > 0:
        if i > 0 and D[i-1][j] and (P[i+j] != i or P[i+j-1] != i-1):
            path = 'S' + path
            i -= 1
        else:
            j -= 1
            path = 'E' + path
            
    print('Case #{}: {}'.format(case, path))

