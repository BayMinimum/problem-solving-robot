#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Plot{
    int x, y;
    bool operator < (const Plot &p) const {
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
    Plot(){}
    Plot(int _x, int _y){
        x = _x; y = _y;
    }
};
Plot P[3];
vector<Plot> Q;

void clean(int x, int y){
    Q.push_back(Plot(x, y));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<3;++i) cin >> P[i].x >> P[i].y;
    sort(P, P+3);
    for(int i=P[0].x;i<P[1].x;++i) clean(i, P[0].y);
    for(int j=min(P[0].y, P[1].y);j<=max(P[0].y, P[1].y);++j) clean(P[1].x, j);
    for(int i=P[1].x+1;i<=P[2].x;++i) clean(i, P[2].y);
    if((P[2].y - P[0].y) * (P[2].y - P[1].y) > 0){
        if(P[0].y < P[2].y) for(int j=max(P[0].y, P[1].y)+1;j<=P[2].y;++j) clean(P[1].x, j);
        else for(int j=min(P[0].y, P[1].y)-1;j>=P[2].y;--j) clean(P[1].x, j);
    }
    cout << Q.size() << '\n';
    for(auto q: Q){
        cout << q.x << ' ' << q.y << '\n';
    }
    return 0;
}
