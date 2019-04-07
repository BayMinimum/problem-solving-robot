T = int(input())
for case in range(1, T+1):
    N = int(input())
    P = input()
    path = ''.join(['S' if p == 'E' else 'E' for p in P])   
    print('Case #{}: {}'.format(case, path))