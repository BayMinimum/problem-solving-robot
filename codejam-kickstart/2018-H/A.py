T = int(input())
for _t in range(1, T+1):
    N, P = [int(x) for x in input().split()]
    X = []
    for i in range(P):
        x = input()
        flag = False
        for j in range(len(X)):
            if x in X[j] and X[j].index(x) == 0:
                X[j] = x
                flag = True
                break
            if X[j] in x and x.index(X[j]) == 0:
                flag = True
                break
        if not flag:
            X.append(x)
    ret = 2 ** N
    for x in X:
        ret -= 2 ** (N - len(x))
    print('Case #{}: {}'.format(_t, ret))

