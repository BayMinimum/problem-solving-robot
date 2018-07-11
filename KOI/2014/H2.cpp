#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 1000000000
#define MAX_M 500000

int N, M;
struct Route{
    int fr, to;
    int i;
    bool operator < (const Route &p) const {
        if(fr == p.fr) return to > p.to;
        else return fr < p.fr;
    }
};
Route R[MAX_M];
int S[MAX_M];
int s = 0;

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;i++){
        scanf("%d %d", &R[i].fr, &R[i].to);
        if(R[i].fr > R[i].to) R[i].to += N;
        R[i].i = i + 1;
    }
    sort(R, R+M);
    int T = 0;
    for(int i=0;i<M;i++) T = max(T, R[i].to);
    T -= N;
    for(int i=0;i<M;i++){
        if(R[i].to > T){
            S[s++] = R[i].i;
            T = R[i].to;
        }
    }
    sort(S, S+s);
    printf("%d", S[0]);
    for(int i=1;i<s;i++) printf(" %d", S[i]);
    printf("\n");
    return 0;
}