#include<cstdio>
#include<algorithm>
using namespace std;
long long N, K, S, D;

int main(){
    scanf("%lld %lld %lld", &N, &K, &S);
    if(S > (N-1) * K || S < K) printf("NO\n");
    else{
        printf("YES\n");
        long long R = 1;
        while(S - K >= 1){
            D = min(S - K + 1, N - 1);
            if(R == 1){
                R = D + 1;
            }
            else{
                R = N - D;
            }
            K--;
            S -= D;
            printf("%lld ", R);
        }
        while(K--){
            if(R == 1) R = 2;
            else R--;
            printf("%lld ", R);
        }
    }
    return 0;
}