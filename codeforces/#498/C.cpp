#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 200000

int N;
long long D[MAX_N + 1], S[MAX_N+1];

long long solve(){
    long long* mid = lower_bound(S+1, S+N+1, S[N]/2);
    long long* a = mid;
    while(a >= S){
        if(binary_search(mid, S+N+1, S[N] - *a)) return *a;
        a--;
    }
}

int main(){
    scanf("%d", &N);
    S[0] = 0;
    for(int i=1;i<=N;i++){
        scanf("%lld", &D[i]);
        S[i] = S[i-1] + D[i];
    }
    printf("%lld\n", solve());
    return 0;
}