def div(n):
    if n % 2 == 0:
        return 2
    i = 3
    while n % i:
        i += 2
    return i


T = int(input())
for case in range(1, T+1):
    N, L = [int(x) for x in input().split()]
    P = [int(x) for x in input().split()]
    a = div(P[0])
    R = [None] * (L+1)
    S = {P[0] // a, a}

    if P[1] != P[0]:
        if P[1] % a == 0:
            R[0] = P[0] // a
            R[1] = a
        else:
            R[0] = a
            R[1] = P[0] // a
    else:
        j = 1
        while P[j] == P[0]:
            j += 1
        if P[j] % a == 0:
            R[j-1] = P[j-1] // a
            R[j] = a
        else:
            R[j-1] = a
            R[j] = P[j-1] // a
        for i in range(j-2, -1, -1):
            R[i] = P[i] // R[i+1]

    for i in range(2, L+1):
        R[i] = P[i-1] // R[i-1]
        S.add(R[i])

    S = sorted(list(S))
    print('Case #{}: '.format(case), end='')
    for i in range(L+1):
        print(chr(S.index(R[i]) + ord('A')), end='')
    print()

    