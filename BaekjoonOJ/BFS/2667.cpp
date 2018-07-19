#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX_N 25

int N;
int M[MAX_N][MAX_N];
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
        return i >= 0 && i < N && j >= 0 && j < N;
    }
};

bool setM(Point p){
    if(p.valid()) if(M[p.i][p.j] == 1){
        M[p.i][p.j] = 0;
        return true;
    }
    return false;
}

int main(){
    scanf("%d", &N);
    char b[N+1];
    for(int i=0;i<N;i++){
        scanf("%s", b);
        for(int j=0;j<N;j++) M[i][j] = b[j] - '0';
    }
    queue<Point> Q;
    vector<int> D;
    Point now, next;
    int count;
    Point dir[] = {Point(1, 0), Point(-1, 0), Point(0, -1), Point(0, 1)};
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        if(M[i][j] == 1){
            Q = {};
            Q.push(Point(i, j));
            count = 0;
            M[i][j] = 0;
            while(!Q.empty()){
                count++;
                now = Q.front();
                Q.pop();
                for(int t=0;t<4;t++){
                    next = Point(now, dir[t]);
                    if(setM(next)){
                        Q.push(next);
                    }
                }
            }
            D.push_back(count);
        }
    }
    sort(D.begin(), D.end());
    printf("%d\n", D.size());
    for(int i=0;i<D.size();i++) printf("%d\n", D[i]);
    return 0;
}