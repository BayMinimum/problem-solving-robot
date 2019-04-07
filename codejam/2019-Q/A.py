T = int(input())
for case in range(1, T+1):
    N = input()
    F = [False] * len(N)
    print('Case #{}:'.format(case), end=' ')
    for i in range(len(N)):
        if N[i] == '4':
            print('{}'.format('2'), end='')
            F[i] = True
        else:
            print('{}'.format(N[i]), end='')
    print(' ', end='')
    j = 0
    while not F[j]:
        j += 1
    while j < len(N):
        print('{}'.format(2 if F[j] else 0), end='')
        j += 1
    print()

