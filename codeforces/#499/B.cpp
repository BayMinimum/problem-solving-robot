#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_A 100
#define MAX_M 100

int C[MAX_A+1];
int N, M;

int main(){
    scanf("%d %d", &N, &M);
    int a;
    for(int i=0;i<MAX_A;i++){
        C[i] = 0;
    }
    for(int i=0;i<M;i++){
        scanf("%d", &a);
        C[a - 1]++;
    }
    sort(C, C+MAX_A);
    reverse(C, C+MAX_A);
    int fr = 0;
    int to = MAX_M;
    int md, s;
    while(fr < to){
        md = (fr + to + 1) / 2;
        s = 0;
        for(int i=0;i<MAX_A;i++) s += C[i] / md;
        if(s >= N) fr = md;
        else to = md - 1;
    }
    printf("%d\n", fr);
    return 0;
}