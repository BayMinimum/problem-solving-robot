#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 5000
int T, N, K;
int A[MAX_N];

int solve(){
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;++i) scanf("%d", A+i);
    sort(A, A+N);
    int day = 0, ate = 0;
    int ret = 0;
    for(int i=0;i<N;++i){
        if(ate == K){
            ++day;
            ate = 0;
        }
        if(day < A[i]){
            ++ate;
            ++ret;
        }
    }
    return ret;
}

int main(){
    scanf("%d", &T);
    for(int _t=1;_t<=T;++_t) printf("Case #%d: %d\n", _t, solve());
    return 0;
}