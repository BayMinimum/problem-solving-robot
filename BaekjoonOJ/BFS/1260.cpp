#include<cstdio>
#include<queue>
using namespace std;
#define MAX_N 1000

int N, M, V;
bool adj[MAX_N+1][MAX_N+1];
bool dfs_visited[MAX_N+1], bfs_visited[MAX_N+1];

void dfs(int fr){
    if(!dfs_visited[fr]){
        dfs_visited[fr] = true;
        printf("%d ", fr);
        for(int i=1;i<=N;i++) if(adj[fr][i]) dfs(i);
    }
}

void bfs(int fr){
    queue<int> visit;
    visit.push(fr);
    int now;
    while(!visit.empty()){
        now = visit.front();
        visit.pop();
        if(!bfs_visited[now]){
            bfs_visited[now] = true;
            printf("%d ", now);
            for(int i=1;i<=N;i++) if(adj[now][i]) visit.push(i);
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &V);
    int fr, to;
    for(int i=0;i<M;i++){
        scanf("%d %d", &fr, &to);
        adj[fr][to] = adj[to][fr] = true;
    }
    dfs(V);
    printf("\n");
    bfs(V);
    return 0;
}