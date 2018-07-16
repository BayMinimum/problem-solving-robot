#include<cstdio>

int N, a;

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &a);
        printf("%d ", (a%2 == 0) ? a-1 : a);
    }
    return 0;
}