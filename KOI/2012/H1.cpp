#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 10000
#define MAX_M 1000000000
int N, M;
int C[MAX_N+1], S[MAX_N+1];

int binary_search(int lo, int hi){
    int md = (lo+hi)/2;
    int s = S[md] + (N-md) * C[md];
    if(s<=M){
        s = S[md+1] + (N-md-1) * C[md+1];
        if(s>M) return md;
        else return binary_search(md+1, hi);
    } else return binary_search(lo, md-1);
}

int main(){
    scanf("%d", &N);
    C[0] = 0;
    for(int i=1;i<=N;i++) scanf("%d", &C[i]);
    scanf("%d", &M);
    sort(C+1, C+N+1);
    S[0] = 0;
    for(int i=1;i<=N;i++) S[i] = S[i-1] + C[i];
    if(S[N] <= M){
        printf("%d\n", C[N]);
    }
    else{
        int t = binary_search(0, N);
        printf("%d\n", (M-S[t]) / (N-t));
    }
    return 0;
}