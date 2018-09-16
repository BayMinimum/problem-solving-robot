#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX_N 200000
int N, M, D;
int C[MAX_N], C0[MAX_N], B[MAX_N];
struct Break{
    int day, time;
    Break(int d, int t){
        day = d;
        time = t;
    }
};
queue<Break> Q;

int main(){
    scanf("%d %d %d", &N, &M, &D);
    for(int i=0;i<N;++i){
        scanf("%d", C+i);
        C0[i] = C[i];
    }
    sort(C, C+N);
    Q.push(Break(1, C[0]));
    B[0] = 1;
    for(int i=1;i<N;++i) {
        if (Q.front().time + D < C[i]) {
            B[i] = Q.front().day;
            Q.pop();
        } else {
            B[i] = Q.size() + 1;
        }
        Q.push(Break(B[i], C[i]));
    }
    printf("%d\n", Q.size());
    for(int i=0;i<N;++i) printf("%d ", B[lower_bound(C, C+N, C0[i]) - C]);
    printf("\n");
    return 0;
}