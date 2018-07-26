#include<cstdio>
#define MAX_N 1000000

int N, M;
int P[MAX_N+1], C[MAX_N+1];

void init(){
    for(int i=0;i<=N;i++) P[i] = C[i] = i;
}

int root(int a){
    if(a == P[a]) return a;
    P[a] = root(P[a]);
    return P[a];
}

bool contained(int a, int b){
    return root(a) == root(b);
}

void merge(int a, int b){
    int u = root(a), v = root(b);
    if(u != v){
        P[u] = v;
        C[v] = u;
        root(C[u]);
    }
}

int main(){
    scanf("%d %d", &N, &M);
    init();
    int cmd, a, b;
    for(int i=0;i<M;i++){
        scanf("%d %d %d", &cmd, &a, &b);
        if(cmd == 0) merge(a, b);
        else printf("%s\n", contained(a, b) ? "YES" : "NO");
    }
    return 0;
}