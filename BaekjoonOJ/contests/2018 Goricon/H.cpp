#include<cstdio>
#include<vector>
using namespace std;
#define MAX_N 123456
int N;
bool isLamb[MAX_N];
long long A[MAX_N];
vector<int> R[MAX_N];

long long solve(int i){
    long long S = 0;
    for(auto j: R[i]){
        S += solve(j);
    }
    if(!isLamb[i]) S -= A[i];
    else S += A[i];
    return S > 0 ? S : 0;
}

int main(){
    scanf("%d", &N);
    char t;
    int a, p;
    for(int i=1;i<N;++i){
        scanf("%s %d %d", &t, &a, &p);
        isLamb[i] = t == 'S';
        R[p-1].push_back(i);
        A[i] = a;
    }
    printf("%lld\n", solve(0));
    return 0;
}