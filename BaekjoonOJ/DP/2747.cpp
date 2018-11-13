#include<cstdio>
#define MAX_N 45
int N;
long long D[MAX_N+1];

int main(){
    D[1] = 1;
    scanf("%d", &N);
    for(int i=2;i<=N;++i) D[i] = D[i-1] + D[i-2];
    printf("%lld\n", D[N]);
    return 0;
}