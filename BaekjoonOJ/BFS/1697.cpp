#include<cstdio>
#include<queue>
using namespace std;
#define MAX_N 100000

int N, K;
int D[MAX_N * 2];

int main(){
    scanf("%d %d", &N, &K);
    for(int i=0;i<MAX_N*2;i++) D[i] = MAX_N * 2;
    queue<int> Q;
    Q.push(N);
    D[N] = 0;
    int now;
    while(Q.front() != K){
        now = Q.front();
        Q.pop();
        if(now < MAX_N) if(D[now * 2] == MAX_N * 2){
            D[now * 2] = D[now] + 1;
            Q.push(now * 2);
        }
        if(now < MAX_N * 2 - 1) if(D[now + 1] == MAX_N * 2){
            D[now + 1] = D[now] + 1;
            Q.push(now + 1);
        }
        if(now > 0) if(D[now - 1] == MAX_N * 2){
            D[now - 1] = D[now] + 1;
            Q.push(now - 1);
        }
    }
    printf("%d\n", D[K]);
    return 0;
}