#include<cstdio>
#include<queue>
using namespace std;
#define MAX_N 100
#define Grs '.'
#define Ice '+'
#define Mt '#'
#define Wf 'W'

int N, M;
char map[MAX_N][MAX_N+1];
bool visited[MAX_N][MAX_N];

void dfs(int i, int j, int di, int dj){
    if(map[i][j] == Mt) return;
    if(map[i][j] == Ice) while(map[i+di][j+dj] != Mt && map[i][j] == Ice){
        i += di;
        j += dj;
    }
    if(!visited[i][j]) {
        visited[i][j] = true;
        dfs(i-1, j, -1, 0);
        dfs(i+1, j, 1, 0);
        dfs(i, j-1, 0, -1);
        dfs(i, j+1, 0, 1);
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i) scanf("%s", map[i]);
    for(int i=0;i<N;++i) for(int j=0;j<M;++j) if(map[i][j] == Wf) dfs(i, j, 0, 0);
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j) printf("%c", map[i][j] == Grs && !visited[i][j] ? 'P' : map[i][j]);
        printf("\n");
    }
    return 0;
}