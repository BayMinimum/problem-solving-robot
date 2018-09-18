#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 40000
int N;
int D[MAX_N], L[MAX_N];

int main(){
    scanf("%d", &N);
    int A;
    int count = 1;
    scanf("%d", D);
    L[0] = 1;
    for(int i=1;i<N;++i){
        scanf("%d", &A);
        int t = lower_bound(D, D+count, A) - D;
        if(t == count){
            ++count;
            D[t] = A;
            L[t] = L[t-1] + 1;
        } else{
            D[t] = A;
        }
    }
    printf("%d\n", L[count-1]);
    return 0;
}