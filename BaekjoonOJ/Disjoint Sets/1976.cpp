#include<cstdio>
#define MAX_N 200

int N, M;
int T[MAX_N+1], C[MAX_N+1];

void init(){
    for(int i=0;i<=N;i++) T[i] = C[i] = i;
}

int find(int a){
    if(a == T[a]) return a;
    T[a] = find(T[a]);
    return T[a];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        T[b] = a;
        C[a] = b;
        find(C[b]);
    }
}

bool solve(){
    int a, b;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){
        scanf("%d", &a);
        if(i < j && a == 1) merge(i, j);
    }
    scanf("%d", &a);
    a = find(a);
    for(int i=1;i<M;i++){
        scanf("%d", &b);
        b = find(b);
        if(a != b) return false;
    }
    return true;
}

int main(){
    scanf("%d %d", &N, &M);
    init();
    printf("%s\n", solve() ? "YES" : "NO");
    return 0;
}