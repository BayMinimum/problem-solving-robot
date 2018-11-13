#include<cstdio>
#include<algorithm>
using namespace std;
int D[3][2];

int main(){
    for(int i=0;i<3;++i) for(int j=0;j<2;++j) scanf("%d", &D[i][j]);
    int dist_d = 0;
    for(int j=0;j<2;++j) dist_d += abs(D[1][j] - D[2][j]);
    int dist_b = 0;
    for(int j=0;j<2;++j) dist_b = max(dist_b, abs(D[0][j] - D[2][j]));
    printf("%s\n", dist_b < dist_d ? "bessie" : (dist_b > dist_d ? "daisy" : "tie"));
    return 0;
}