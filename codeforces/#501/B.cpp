#include<cstdio>
#include<queue>
using namespace std;
#define MAX_N 50
#define MAX_D 10000

int N;
char S[MAX_N+1], T[MAX_N+1];
int L[MAX_N+1];
int K;
queue<int> F[26];

int main(){
    scanf("%d", &N);
    scanf("%s %s", S, T);
    for(int i=0;i<N;i++) F[S[i] - 'a'].push(i);
    int m;
    for(int i=0;i<N;i++){
        L[i] = F[T[i] - 'a'].front() + i;
        F[T[i] - 'a'].pop();
        K += L[i] - i;
    }
    if(K < MAX_N){
        printf("%d\n", K);
        for(int i=0;i<N;i++){
            while(L[i] > i) printf("%d\n", L[i]--);
        }
    }
    else printf("-1\n");
    return 0;
}