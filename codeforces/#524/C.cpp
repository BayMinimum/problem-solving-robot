#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int N, M;
int x[4], y[4];

long long count_black(long long x1, long long y1, long long x2, long long y2){
    if(x1 > x2 || y1 > y2) return 0;
    if((x2 - x1) % 2 == 1 || (y2 - y1) % 2 == 1)
        return ((x2 - x1) + 1) * ((y2 - y1) + 1) / 2;
    if((x1 + y1) % 2) return ((x2 - x1) + 1) * ((y2 - y1) + 1) / 2 + 1;
    return ((x2 - x1) + 1) * ((y2 - y1) + 1) / 2;
}

long long area(long long x1, long long y1, long long x2, long long y2){
    if(x1 > x2 || y1 > y2) return 0;
    return ((x2 - x1) + 1) * ((y2 - y1) + 1);
}

long long count_white(long long x1, long long y1, long long x2, long long y2){
    return area(x1, y1, x2, y2) - count_black(x1, y1, x2, y2);
}

int main(){
    scanf("%d", &T);
    for(int t=0;t<T;++t) {
        scanf("%d %d", &N, &M);
        for(int i=0;i<4;++i) scanf("%d %d", x+i, y+i);
        long long black = count_black(1, 1, N, M);
        black -= count_black(x[0], y[0], x[1], y[1]);
        black += count_white(x[2], y[2], x[3], y[3]);
        black += count_black(max(x[0], x[2]), max(y[0], y[2]), min(x[1], x[3]), min(y[1], y[3]));
        printf("%lld %lld\n", area(1, 1, N, M) - black, black);
    }
    return 0;
}