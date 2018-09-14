#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 100000

int N;
long long M;
long long D[MAX_N];
long long SA, SB;

int main(){
    scanf("%d %lld", &N, &M);
    long long A, B;
    for(int i=0;i<N;i++){
        scanf("%lld %lld", &A, &B);
        SA += A;
        SB += B;
        D[i] = A - B;
    }
    if(SB > M) printf("-1\n");
    else{
        sort(D, D+N);
        int i = N - 1;
        while(SA > M){
            SA -= D[i--];
        }
        printf("%d\n", N - 1 - i);
    }
    return 0;
}