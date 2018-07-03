#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 200000
#define MAX_logN 30
int n, q;
int a[MAX_logN+1];
int c[MAX_logN+1];

int main(){
    scanf("%d %d", &n, &q);
    a[0] = 1;
    c[0] = 0;
    for(int i=1;i<=MAX_logN;i++){
        a[i] = a[i-1] * 2;
        c[i] = 0;
    }
    int in;
    for(int i=0;i<n;i++){
        scanf("%d", &in);
        c[find(a, a+MAX_logN+1, in) - a]++;
    }
    int Q, C, t;
    for(int _q=0;_q<q;_q++){
        scanf("%d", &Q);
        C = 0;
        int i = upper_bound(a, a+MAX_logN+1, Q) - a - 1;
        while(Q>0){
            if(i==-1){
                C = -1;
                break;
            }
            t = min(Q/a[i], c[i]);
            Q -= a[i] * t;
            C += t;
            i--;
        }
        printf("%d\n", C);
    }
    return 0;
}