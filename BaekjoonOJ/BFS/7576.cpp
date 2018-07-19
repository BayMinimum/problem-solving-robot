#include<cstdio>
#include<queue>
using namespace std;
#define MAX_N 1000

int M, N;
int T[MAX_N][MAX_N], D[MAX_N][MAX_N];
struct Point{
    int i, j;
    Point(){
        i = j = 0;
    }
    Point(int _i, int _j){
        i = _i;
        j = _j;
    }
    Point(Point p, Point d){
        i = p.i + d.i;
        j = p.j + d.j;
    }
    bool valid(){
        return i >= 0 && i < N && j >= 0 && j < M;
    }
};

int main(){
    scanf("%d %d", &M, &N);
    queue<Point> Q;
    const int INF = MAX_N * MAX_N;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++){
        scanf("%d", &T[i][j]);
        if(T[i][j] == 1){
            Q.push(Point(i, j));
            D[i][j] = 0;
        }
        else D[i][j] = INF;
    }
    Point now, next;
    const Point dir[] = {Point(0, 1), Point(0, -1), Point(1, 0), Point(-1, 0)};
    while(!Q.empty()){
        now = Q.front();
        Q.pop();
        for(int t=0;t<4;t++){
            next = Point(now, dir[t]);
            if(next.valid()) if(T[next.i][next.j] == 0){
                D[next.i][next.j] = D[now.i][now.j] + 1;
                T[next.i][next.j] = 1;
                Q.push(next);
            }
        }
    }
    int mx = 0;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(T[i][j] >= 0 && D[i][j] > mx) mx = D[i][j];
    if(mx == INF) mx = -1;
    printf("%d\n", mx);
    return 0;
}