#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 100
int N, M;
int S_A, M_A;

int solve_min(){
    if(S_A % N == 0) return S_A / N;
    else return S_A / N + 1;
}

int solve_max(){
    return M_A + M;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    S_A += M;
    int a;
    for(int i=0;i<N;++i){
        cin>>a;
        S_A += a;
        if(a > M_A) M_A = a;
    }
    cout<<max(solve_min(), M_A)<<' '<<solve_max()<<endl;
    return 0;
}