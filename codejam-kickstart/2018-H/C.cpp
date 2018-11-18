#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 100
const int MOD = 1000000007;
int T, N, M;
long long D[MAX_N+1][MAX_N*2+1];

int main(){
    scanf("%d", &T);
    for(int _t=1;_t<=T;++_t){
        scanf("%d %d", &N, &M);
        for(int j=3;j<=N*2;++j) D[1][j] = j - 2;
        for(int i=2;i<=M;++i) {
            for (int j = 3; j <= N*2; ++j) {
                D[i][j] = 0;
                for (int k = 3; k < j; ++k) {
                    D[i][j] += D[i - 1][k] * (j == k + 1 ? k - 2 * i + 2 : j - 2 * i);
                    D[i][j] %= MOD;
                }
            }
        }
        long long r = 0;
        for(int j=3;j<=N*2;++j) r += D[M][j];
        r %= MOD;
        long long f = 1;
        for(int j=1;j<=M;++j) {
            f *= 2;
            f *= j;
            f %= MOD;
        }
        for(int j=1;j<=2*(N-M);++j) {
            f *= j;
            f %= MOD;
        }
        printf("Case #%d: %lld\n", _t, (r * f) % MOD);
    }
    return 0;
}