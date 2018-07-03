#include<cstdio>
#define min(a, b) (a<b ? a : b)
#define max(a, b) (a>b ? a : b)
int a, b, x;

int main(){
    scanf("%d %d %d", &a, &b, &x);
    int pr = 0;
    if(a < b) pr = 1;
    int ini = pr;
    for(int i=0;i<x;i++){
        printf("%d", pr);
        pr = 1 - pr;
    }
    pr = 1 - pr;
    if(x%2 == 0){
        for(int i=0;i<min(a, b) - x/2;i++) printf("%d", 1-ini);
        for(int i=0;i<max(a, b) - x/2;i++) printf("%d", ini);
    }
    else{
        for(int i=0;i<max(a, b) - (x+1)/2;i++) printf("%d", ini);
        for(int i=0;i<min(a, b) - x/2;i++) printf("%d", 1-ini);
    }
    printf("\n");
    return 0;
}