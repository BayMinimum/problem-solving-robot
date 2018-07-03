#include<cstdio>
#define MAX_A 100
#define max(a, b) (a>b ? a : b)
int n, a, m;
int count[MAX_A + 1];

int main(){
    for(int i=1;i<=MAX_A;i++) count[i] = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        count[a]++;
    }
    m = 0;
    for(int i=1;i<=MAX_A;i++) m = max(m, count[i]);
    printf("%d\n", m);
    return 0;
}