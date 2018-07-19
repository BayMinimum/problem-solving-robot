#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_N 100

int M, N, K;
bool A[MAX_N][MAX_N];
struct Point{
    int i, j;
    Point(){
        i = j = 0;
    }
    Point(int _i, int _j){
        i = _i;
        j = _j;
    }
    Point(Point &p, Point &d){
        i = p.i + d.i;
        j = p.j + d.j;
    }
    bool valid(){
        return i >= 0 && i < M && j >= 0 && j < N;
    }
};

int main(){
    scanf("%d %d %d", &M, &N, &K);
    int l, r, d, u;
    for(int k=0;k<K;k++){
        scanf("%d %d %d %d", &l, &d, &r, &u);
        for(int i=d;i<u;i++) for(int j=l;j<r;j++) A[i][j] = true;
    }
    Point now, next;
    Point dir[] = {Point(0, 1), Point(0, -1), Point(1, 0), Point(-1, 0)};
    vector<int> count;
    int area;
    for(int i=0;i<M;i++) for(int j=0;j<N;j++){
        if(!A[i][j]){
            A[i][j] = true;
            area = 1;
            queue<Point> Q;
            Q.push(Point(i, j));
            while(!Q.empty()){
                now = Q.front();
                Q.pop();
                for(int t=0;t<4;t++){
                    next = Point(now, dir[t]);
                    if(next.valid()) if(!A[next.i][next.j]){
                        A[next.i][next.j] = true;
                        Q.push(next);
                        area++;
                    }
                }
            }
            count.push_back(area);
        }
    }
    printf("%d\n", count.size());
    sort(count.begin(), count.end());
    for(int i=0;i<count.size();i++) printf("%d ", count[i]);
    return 0;
}