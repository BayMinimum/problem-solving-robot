#include<cstdio>
#define MAX_N 100

int N, M;
bool T[MAX_N+1];
int L, R;

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        scanf("%d %d", &L, &R);
        for(int j=L;j<=R;j++) T[j] = true;
    }
    int S = 0;
    for(int j=1;j<=M;j++) if(!T[j]) S++;
    printf("%d\n", S);
    for(int j=1;j<=M;j++) if(!T[j]) printf("%d ", j);
    printf("\n");
    return 0;
}