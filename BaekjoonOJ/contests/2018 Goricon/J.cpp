#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 30
int N, M;
int A[MAX_N][MAX_N];
int S[MAX_N];
int R;

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i) for(int j=0;j<M;++j) scanf("%d", &A[i][j]);
    for(int k1=0;k1<M-2;++k1){
        int r1 = 0;
        for(int i=0;i<N;++i) r1 += A[i][k1];
        for(int k2=k1+1;k2<M-1;++k2){
            int r2 = 0;
            for(int i=0;i<N;++i) r2 += max(A[i][k2] - A[i][k1], 0);
            for(int k3=k2+1;k3<M;++k3){
                int r3 = 0;
                for(int i=0;i<N;++i) r3 += max(A[i][k3] - max(A[i][k2], A[i][k1]), 0);
                R = max(R, r1 + r2 + r3);
            }
        }
    }
    printf("%d\n", R);
    return 0;
}