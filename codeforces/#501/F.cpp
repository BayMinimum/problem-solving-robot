#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_L 200
const long long MOD = 1000000007;
long long D[MAX_L+1][MAX_L+1], D2[MAX_L+1][MAX_L+1];
int N, P, V, T, L;

void dp(int M){
    D[0][0] = D2[0][0] = 1;
    for(int i=1;i<=M;i++){
        D[i][0] = D[i-1][1];
        D2[i][0] = D2[i-1][1];
        if(i == L && 0 == T){
            D2[i][0]--;
        }
        for(int j=1;j<=i;j++){
            D[i][j] = D[i-1][j-1];
            if(j+1 <= i-1) D[i][j] += D[i-1][j+1];
            D[i][j] %= MOD;
            D2[i][j] = D2[i-1][j-1];
            if(j+1 <= i-1) D2[i][j] += D2[i-1][j+1];
            if(i == L && j == -T){
                D2[i][j]--;
            }
            D2[i][j] %= MOD;
        }
    }
}

int main(){
    scanf("%d", &N);
    char S[N*2+1];
    scanf("%s", S);
    L = strlen(S);
    for(int i=0;i<L;i++){
        if(S[i] == '(') T--;
        else T++;
        P = max(P, T);
        V = min(V, T);
    }
    if(T > 0){
        T = -T;
        P = V;
    }
    dp(N*2 - L);
    long long C = 0;
    for(int i=P;i<=2*N-L;i++){
        for(int j=P;j<=i;j++){
            if(j - T <= 2*N-L-i){
            C += D2[i][j] * D[2*N-L-i][j - T];
            C %= MOD;
            }
        }
    }
    printf("%lld\n", C);
    return 0;
}