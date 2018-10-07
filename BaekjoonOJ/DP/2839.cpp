#include<cstdio>
#define min(a, b) ((a)<(b) ? (a) : (b))
#define MAX_N 5000
const int inf = MAX_N;
int N;
int D[MAX_N+1];
int main(){
    scanf("%d", &N);
    D[0] = 0;
    D[1] = D[2] = D[4] = inf;
    D[3] = 1;
    for(int i=5;i<=N;++i) D[i] = min(D[i-3], D[i-5]) + 1;
    printf("%d\n", D[N] < 5000 ? D[N] : -1);
    return 0;
}