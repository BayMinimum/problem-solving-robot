#include<cstdio>
#include<queue>
using namespace std;
#define MAX_N 100
int N;
int adj[MAX_N][MAX_N], path[MAX_N];
bool visited[MAX_N];

void bfs(int fr){
	for(int i=0;i<N;i++) visited[i] = path[i] = 0;
	queue<int> Q;
	Q.push(fr);
	int now;
	while(!Q.empty()){
		now = Q.front();
		Q.pop();
		for(int i=0;i<N;i++) if(adj[now][i] == 1 && visited[i] == 0){
			visited[i] = 1;
			path[i] = 1;
			Q.push(i);
		}
	}
}

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) scanf("%d", &adj[i][j]);
	for(int i=0;i<N;i++){
		bfs(i);
		for(int j=0;j<N;j++) printf("%d ", path[j]);
		printf("\n");
	}
	return 0;
}