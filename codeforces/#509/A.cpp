#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 1000
int N;
long long A[MAX_N];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;++i) scanf("%lld", A+i);
    sort(A, A+N);
    printf("%lld\n", A[N-1] - A[0] - N + 1);
    return 0;
}