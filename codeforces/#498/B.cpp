#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 2000

int N, K;
struct Problem{
    int a, i;
    bool operator < (const Problem &p) const {
        if(a != p.a) return a < p.a;
        else return i < p.i;
    }
};
Problem A[MAX_N];
int I[MAX_N+1];

int sum(Problem* fr, Problem* to){
    int ret = 0;
    while(fr < to){
        ret += (*fr).a;
        fr++;
    }
    return ret;
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i=0;i<N;i++){
        scanf("%d", &A[i].a);
        A[i].i = i;
    }
    sort(A, A+N);
    printf("%d\n", sum(A+N-K, A+N));
    for(int i=0;i<K;i++) I[i+1] = A[i+N-K].i;
    sort(I+1, I+K+1);
    I[0] = -1;
    for(int i=0;i<K-1;i++) printf("%d ", I[i+1] - I[i]);
    printf("%d\n", N - I[K - 1] - 1);
}