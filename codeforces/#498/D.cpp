#include<cstdio>
#define MAX_N 100000
#define rev(i) (N-(i)-1)

int N;
char A[MAX_N+1], B[MAX_N+1];

int main(){
    scanf("%d", &N);
    scanf("%s %s", A, B);
    int ret = 0;
    for(int i=0;i<N/2;i++){
        if(B[i] == B[rev(i)]){
            if(A[i] != A[rev(i)]) ret++;
        }
        else{
            if(A[i] != B[i] && A[rev(i)] != B[i]) ret++;
            if(A[i] != B[rev(i)] && A[rev(i)] != B[rev(i)]) ret++;
        }
    }
    if(N%2 == 1) if(A[N/2] != B[N/2]) ret++;
    printf("%d\n", ret);
    return 0;
}