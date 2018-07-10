#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 5000

int N;
long long C[MAX_N];
int I, J, K;
long long M=3000000001;

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%lld", &C[i]);
    sort(C, C+N);
    for(int i=0;i<N-2;i++){
        int k = N-1;
        for(int j=i+1;j<N-1;j++){
            if(k <= j) break;
            while(k-1 > j && abs(C[i] + C[j] + C[k-1]) < abs(C[i] + C[j] + C[k])) k--;
            if(abs(C[i] + C[j] + C[k]) < M){
                M = abs(C[i] + C[j] + C[k]);
                I = i;
                J = j;
                K = k;
            }
        }
    }
    printf("%lld %lld %lld\n", C[I], C[J], C[K]);
    return 0;
}