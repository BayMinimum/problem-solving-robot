#include<cstdio>
#define MAX_N 15
int N;
int T, P;
int D[MAX_N+1];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;++i){
        scanf("%d %d", &T, &P);
        if(D[i] + P > D[i+T]) D[i+T] = D[i] + P;
        if(D[i+1] < D[i]) D[i+1] = D[i];
    }
    printf("%d\n", D[N]);
    return 0;
}