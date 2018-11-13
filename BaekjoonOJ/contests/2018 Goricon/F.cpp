#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 1000
int N, L;
int H[MAX_N];

int main(){
    scanf("%d %d", &N, &L);
    for(int i=0;i<N;++i) scanf("%d", H+i);
    sort(H, H+N);
    int i=0;
    while(i < N && H[i++] <= L) L += 1;
    printf("%d\n", L);
    return 0;
}