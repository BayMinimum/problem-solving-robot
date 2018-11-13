#include<cstdio>
#define MAX_N 100000
int N, M;
int S[MAX_N+1];

int main(){
    int a;
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;++i){
        scanf("%d", &a);
        S[i] += S[i-1] + a;
    }
    ++M;
    int i, j;
    while(--M){
        scanf("%d %d", &i, &j);
        printf("%d\n", S[j] - S[i-1]);
    }
    return 0;
}