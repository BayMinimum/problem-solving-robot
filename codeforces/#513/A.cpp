#include<cstdio>
#define min(a, b) ((a)<(b) ? (a):(b))
int N;
char S[101];
int C;

int main(){
    scanf("%d", &N);
    scanf("%s", S);
    for(int i=0;i<N;++i) if(S[i] == '8') ++C;
    printf("%d\n", min(N/11, C));
    return 0;
}