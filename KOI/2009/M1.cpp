#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 5000000
#define MAX_M (MAX_N * 10000LL)
#define quadratic(a, b, c, x) (a * (x) * (x) + b * (x) + c)

int N;
long long A[MAX_N];
long long S[MAX_N];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%lld", &A[i]);
    sort(A, A+N);
    S[0] = A[0];
    for(int i=1;i<N;i++) S[i] = S[i-1] + A[i];
    // idea 1
    long long M = MAX_M + 1, m;
    int B;
    for(int i=0;i<N;i++){
        m = S[N-1] - 2 * S[i-1] - A[i] * (N-i*2);
        if(m<M){
            M = m;
            B = i;
        }
    }
    // idea 2
    long long B2 = S[N-1] / (long long) N;
    long long a = N, b = -2 * S[N-1], c = 0;
    for(int i=0;i<N;i++) c += A[i] * A[i];
    if(quadratic(a, b, c, B2) > quadratic(a, b, c, B2+1)) B2++;
    printf("%lld %lld", A[B], B2);
    return 0;
}