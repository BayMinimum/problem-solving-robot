#include<cstdio>
#include<algorithm>
using namespace std;
int n, d, m;
int x, y;
int main(){
    scanf("%d %d %d", &n, &d, &m);
    for(int i=0;i<m;++i){
        scanf("%d %d", &x, &y);
        printf("%s\n", (x+y >= d && x+y <= 2*n-d && abs(x-y) <= d) ? "yes" : "no");
    }
    return 0;
}