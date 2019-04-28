T = int(input())

for case in range(1, T+1):
    N, K = [int(x) for x in input().split()]
    C = [int(x) for x in input().split()]
    D = [int(x) for x in input().split()]
    MC, MD = [[0]*N for i in range(N)], [[0]*N for i in range(N)]
    cnt = 0
    for i in range(N):
        MC[i][i] = C[i]
        MD[i][i] = D[i]
        if abs(C[i]-D[i]) <= K:
            cnt += 1
        for j in range(i+1, N):
            MC[i][j] = max(MC[i][j-1], C[j])
            MD[i][j] = max(MD[i][j-1], D[j])
            if abs(MC[i][j]-MD[i][j]) <= K:
                cnt += 1
    print('Case #{}: {}'.format(case, cnt))