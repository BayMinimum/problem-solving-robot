#include<cstdio>
int N, R, C;

int main(){
    scanf("%d %d %d", &N, &R, &C);
    int f = (R + C) % 2;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j) printf("%c", (i + j) % 2 == f ? 'v' : '.');
        printf("\n");
    }
    return 0;
}