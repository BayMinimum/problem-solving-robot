#include<cstdio>
int N, k;
int main(){
    scanf("%d", &N);
    bool easy = true;
    for(int i=0;i<N;++i){
        scanf("%d", &k);
        if(k) easy = false;
    }
    printf("%s\n", easy ? "easy" : "hard");
    return 0;
}