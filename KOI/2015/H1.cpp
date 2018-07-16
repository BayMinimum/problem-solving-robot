#include<cstdio>
#define abs(a) ((a) > 0 ? (a) : -(a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX_K 1000

int K, C, M, N;
bool D[MAX_K + 2][MAX_K + 2];

bool canContinue(int m, int n, int k1, int k2){
    return (n - m <= k1) && (m - n <= k2);
}

void solve(){
    for(int i=0;i<=K + 1;i++) for(int j=0;j<=K + 1;j++) D[i][j] = false;
    D[0][0] = true;
    for(int i=0;i<=K;i++) for(int j=0;j<=K;j++) if(D[i][j]){
        if(canContinue(i, j, K - max(i, j), K - max(i, j))){
            D[i+1][j] = true;
            if(canContinue(i+1, j, K - max(i, j) - 1, K - max(i, j))) D[i+1][j+1] = true;
            if(canContinue(i, j, K - max(i, j) - 1, K - max(i, j))) D[i][j+1] = true;
        }
    }
}

int main(){
    scanf("%d", &K);
    solve();
    scanf("%d", &C);
    for(int i=0;i<C;i++){
        scanf("%d %d", &M, &N);
        printf("%d\n", D[M][N] ? 1 : 0);
    }
    return 0;
}