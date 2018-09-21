#include<cstdio>
int n, m;
int main(){
    scanf("%d", &n);
    ++n;
    int x, y;
    while(--n){
        scanf("%d %d", &x, &y);
        if(x + y > m) m = x + y;
    }
    printf("%d\n", m);
    return 0;
}