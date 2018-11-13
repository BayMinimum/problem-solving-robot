#include<cstdio>
#define MAX_N 99
int N;

int main(){
    scanf("%d", &N);
    int S = 64;
    while(S > 0){
        if(S >= N){
            for(int i=0;i<N/2;++i) printf("A");
            for(int i=N/2;i<N;++i) printf("B");
        }
        else for (int i = 0; i < N; ++i) printf("%c", i % (S * 2) < S ? 'A' : 'B');
        printf("\n");
        S /= 2;
    }
    return 0;
}