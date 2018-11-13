#include<cstdio>
#define MAX_N 200000
int N;
int S[MAX_N+1];
char s[MAX_N+1];

int main(){
    scanf("%d", &N);
    scanf("%s", s);
    for(int i=1;i<=N;++i){
        if(s[i-1] == 's') S[i] = S[i-1] + 1;
        else S[i] = S[i-1] - 1;
    }
    if(S[N/2] == 0) printf("1\n%d\n", N/2);
    else{
        for(int i=1;i<N/2;++i){
            if(S[i+N/2] - S[i] == 0){
                printf("2\n%d %d\n", i, i+N/2);
                break;
            }
        }
    }
    return 0;
}