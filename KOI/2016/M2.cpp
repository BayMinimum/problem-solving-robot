#include<cstdio>
#define MAX_N 100000
int N;
int D[MAX_N];
long long S=0, T=1000000001;

int main(){
    scanf("%d", &N);
    for(int i=0;i<N-1;i++) scanf("%d", &D[i]);
    int P;
    for(int i=0;i<N-1;i++){
        scanf("%d", &P);
        if(P<T) T = P;
        S += T * (long long) D[i];
    }
    printf("%lld\n", S);
    return 0;
}