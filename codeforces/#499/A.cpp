#include<cstdio>
#define MAX_N 50
#define min(a, b) ((a) < (b) ? (a) : (b))

int N, K;
char I[MAX_N+1];
bool L[27];
int D[27][MAX_N+1];

int main(){
    scanf("%d %d", &N, &K);
    scanf("%s", I);
    for(int i=0;i<N;i++) L[I[i] - 'a' + 1] = true;
    int l = 26;
    for(int i=1;i<=26;i++) if(L[i]){
        l = i;
        break;
    }
    const int INF = 26 * 26;
    D[l][1] = l;
    D[l-1][1] = INF;
    for(int i=2;i<=K;i++) D[l][i] = D[l-1][i] = INF;
    for(int i=l+1;i<=26;i++){
        D[i][0] = 0;
        if(L[i]){
            for(int j=1;j<=K;j++) D[i][j] = min(D[i-1][j], min(D[i-2][j-1], (i >= 3 ? D[i-3][j-1] : INF)) + i);
        } else{
            for(int j=1;j<=K;j++) D[i][j] = D[i-1][j];
        }
    }
    printf("%d\n", D[26][K] >= INF ? -1 : D[26][K]);
    return 0;
}