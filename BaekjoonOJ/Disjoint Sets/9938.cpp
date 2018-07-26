#include<cstdio>
#define MAX_N 300000

int N, L;
int T[MAX_N+1];

void init(){
    for(int i=0;i<=L;i++) T[i] = i;
}

int root(int a){
    if(a == T[a]) return a;
    T[a] = root(T[a]);
    return T[a];
}

void store(int to, int alt){
    if(root(alt) != to) T[to] = alt;
    else T[to] = 0;
}

bool solve(int A, int B){
    int rtA = root(A);
    if(A == rtA){
        store(A, B);
        return true;
    }
    int rtB = root(B);
    if(B == rtB){
        store(B, A);
        return true;
    }
    if(rtA != 0){
        store(rtA, B);
        return true;
    }
    if(rtB != 0){
        store(rtB, A);
        return true;
    }
    return false;
}

int main(){
    scanf("%d %d", &N, &L);
    init();
    int A, B;
    for(int i=0;i<N;i++){
        scanf("%d %d", &A, &B);
        printf("%s\n", solve(A, B) ? "LADICA" : "SMECE");
    }
    return 0;
}