#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 5000000
int T, N, B;
char P[MAX_N+2];
int S[MAX_N+1];

int main(){
    scanf("%d", &T);
    for(int _t=1;_t<=T;++_t){
        scanf("%d", &N);
        scanf("%s", P+1);
        S[0] = 0;
        for(int i=1;i<=N;++i) S[i] = S[i-1] + (P[i] - '0');
        B = 0;
        int k = (N+1)/2;
        for(int i=k;i<=N;++i) B = max(B, S[i] - S[i-k]);
        printf("Case #%d: %d\n", _t, B);
    }
    return 0;
}