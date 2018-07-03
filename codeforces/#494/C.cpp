#include<cstdio>
#define MAX_N 5000
#define max(a, b) (a>b ? a : b)
int n, k;
int a[MAX_N];

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    int S = 0, M2;
    double M = 0.0;
    for(int j=k;j<=n;j++){
        S = 0;
        for(int i=0;i<j;i++) S += a[i];
        M2 = S;
        for(int i=j;i<n;i++){
            S += a[i];
            S -= a[i-j];
            M2 = max(M2, S);
        }
        M = max(M, M2*1.0/j);
    }
    printf("%.15f\n", M);
    return 0;
}