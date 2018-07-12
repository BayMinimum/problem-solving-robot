#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 100000
#define DIV 20070713

struct Robot{
    int fr, to;
    bool operator < (const Robot &r) const {
        if(to != r.to) return to < r.to;
        else return fr > r.fr;
    }
};
Robot R[MAX_N];
Robot C;
int N;
long long A[MAX_N];

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d %d", &R[i].fr, &R[i].to);
    sort(R, R+N);
    int s;
    A[0] = 2;
    for(int i=1;i<N;i++){
        C.fr = -1;
        C.to = R[i].fr;
        s = lower_bound(R, R+i, C) - R - 1;
        A[i] = ((s >= 0 ? A[s] : 1) + A[i-1]) % DIV;
    }
    printf("%lld\n", A[N-1]);
    return 0;
}