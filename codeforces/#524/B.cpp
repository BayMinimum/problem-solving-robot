#include<cstdio>
int Q;

int solve(int l, int r){
    if((r-l) % 2 == 0){
        if(r % 2 == 0) return - (r-l)/2 + r;
        else return (r-l)/2 - r;
    }
    if(r % 2 == 0) return (r-l + 1)/2;
    return -(r-l + 1)/2;
}

int main(){
    scanf("%d", &Q);
    int l, r;
    for(int i=0;i<Q;++i){
        scanf("%d %d", &l, &r);
        printf("%d\n", solve(l, r));
    }
    return 0;
}