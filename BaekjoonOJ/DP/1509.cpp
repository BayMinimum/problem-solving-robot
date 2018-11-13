#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_L 2500

int D[MAX_L];
bool P[MAX_L][MAX_L];
char S[MAX_L+1];
int L;

int main(){
    scanf("%s", S);
    L = strlen(S);
    long long d;
    for(int i=0;i<L;++i){
        P[i][i] = true;
    }
    for(int i=0;i<L-1;++i){
        P[i][i+1] = S[i] == S[i + 1];
    }
    for(int k=3;k<=L;++k) for(int i=0;i<=L-k;++i){
            if(S[i] == S[i+k-1] && P[i+1][i+k-2]) P[i][i+k-1] = true;
    }
    D[0] = 1;
    for(int i=1;i<L;++i){
        if(P[0][i]) D[i] = 1;
        else {
            D[i] = i + 1;
            for (int j = i-1;j>=0;--j) if (P[j+1][i]) D[i] = min(D[i], D[j] + 1);
        }
    }
    printf("%d\n", D[L-1]);
    return 0;
}