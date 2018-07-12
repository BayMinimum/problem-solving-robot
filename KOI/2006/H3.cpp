#include<cstdio>
#define MAX_N 8192
#define MAX_lgN 13
int N, M;
int R[MAX_N];

int main(){
    scanf("%d %d", &N, &M);
    if(N==2){
        printf("%d %d\n", M, 3-M);
    }
    else{
        R[0] = M;
        R[1] = N - M + 1;
        int T = 2;
        int d;
        while(T < N){
            d = T / 2;
            if((M - 1) % T + 1 > d) d = -d;
            for(int i=T;i<2*T;i++) R[i] = R[i - T] + ((i%2 == 0) ? d : -d);
            T *= 2;
        }
        for(int i=0;i<N;i++){
            printf("%d ", R[i]);
        }
    }
    return 0;
}