import sys
T, W = [int(x) for x in input().split()]

for case in range(1, T+1):
    print(224)
    sys.stdout.flush()
    D228 = str(bin(int(input())))[2:]
    n = len(D228)
    D228 = '0'*(63-n) + D228
    n = 63
    R6 = int(D228[n-37-7:n-37], base=2)
    R5 = int(D228[n-44-7:n-44], base=2)
    R4 = int(D228[n-56-7:n-56], base=2)

    print(56)
    sys.stdout.flush()
    D57 = str(bin(int(input())-R4*2**14-R5*2**11-R6*2**9))[2:]
    n = len(D57)
    D57 = '0'*(63-n) + D57
    n = 63
    R3 = int(D57[n-18-7:n-18], base=2)
    R2 = int(D57[n-28-7:n-28], base=2)
    R1 = int(D57[n-56-7:n-56], base=2)

    print(R1, R2, R3, R4, R5, R6)
    sys.stdout.flush()
    
    if input() == -1:
        sys.exit(-1)