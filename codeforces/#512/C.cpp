#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 100
int N;
char A;
int S[MAX_N+1];
bool solve2(int i){
    int j = i + 1;
    while(j <= N){
        bool flag = false;
        for(int k=j;k<=N;++k){
            int s = S[k] - S[j-1];
            if(s == S[i]){
                j = k + 1;
                flag = true;
                break;
            } else if(s > S[i]) return false;
        }
        if(!flag) break;
    }
    return j == N + 1;
}
bool solve(){
    for(int i=1;i<N;++i) if(solve2(i)) return true;
    return false;
}
int main(){
    scanf("%d", &N);
    while(getchar() != '\n'){}
    for(int i=1;i<=N;++i){
        scanf("%c", &A);
        if(A == '0'){
            --N; --i;
        } else S[i] = S[i-1] + (A - '0');
    }
    printf("%s\n", N==0 || solve() ? "yes" : "no");
    return 0;
}