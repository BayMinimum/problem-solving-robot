#include<cstdio>
#include<queue>
using namespace std;
#define MAX_N 100

int N, M;
bool movable[MAX_N][MAX_N];
struct Point{
    int x, y;
    Point(){
        x = y = 0;
    }
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
    Point(const Point p, Point d){
        x = p.x + d.x;
        y = p.y + d.y;
    }
};
int D[MAX_N][MAX_N];
int getD(Point p){
    return D[p.x][p.y];
}
bool setD(Point p, int v){
    if(p.x >= 0 && p.x < N && p.y >= 0 && p.y < M){
        if(v < getD(p)){
            D[p.x][p.y] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d %d", &N, &M);
    char b[M+1];
    for(int i=0;i<N;i++){
        scanf("%s", b);
        for(int j=0;j<M;j++){
            movable[i][j] = (b[j] == '1');
            D[i][j] = MAX_N * MAX_N + 1;
        }
    }
    D[0][0] = 1;
    queue<Point> Q;
    Q.push(Point(0, 0));
    Point now;
    Point dir[] = {Point(1, 0), Point(0, 1), Point(0, -1), Point(-1, 0)};
    while(!Q.empty()){
        now = Q.front();
        Q.pop();
        int nextD = getD(now) + 1;
        for(int i=0;i<4;i++){
            Point next = Point(now, dir[i]);
            if(movable[next.x][next.y]) if(setD(next, nextD)) Q.push(next);
        }
    }
    printf("%d\n", D[N-1][M-1]);
    return 0;
}
