#include<cstdio>
#define MAX_N 1024
int N, M;
int S[MAX_N+1][MAX_N+1];

int main(){
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;++i) for(int j=1;j<=N;++j){
        scanf("%d", &S[i][j]);
        S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1];
    }
    ++M;
    int x1, y1, x2, y2;
    while(--M){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1]);
    }
    return 0;
}