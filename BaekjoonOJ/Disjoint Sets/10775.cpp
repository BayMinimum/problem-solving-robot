#include<cstdio>
#define MAX_G 100000

int G, P;
int D[MAX_G+1];

void init(){
    for(int i=0;i<=G;i++) D[i] = i;
}

int find(int a){
    if(a == D[a]) return a;
    D[a] = find(D[a]);
    return D[a];
}

bool dock(int i){
    int d = find(i);
    if(d == 0) return false;
    D[d] = d - 1;
    return true;
}

int solve(){
    int g;
    for(int i=0;i<P;i++){
        scanf("%d", &g);
        if(!dock(g)) return i;
    }
    return P;
}

int main(){
    scanf("%d %d", &G, &P);
    init();
    printf("%d\n", solve());
    return 0;
}