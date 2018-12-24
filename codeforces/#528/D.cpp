#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX_N 100000
int C[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, S;
    cin >> N >> S;
    int a, b;
    for(int i=0;i<N-1;++i){
        cin >> a >> b;
        ++C[a-1];
        ++C[b-1];
    }
    int L = 0;
    for(int i=0;i<N;++i){
        if(C[i] == 1) ++L;
    }
    cout.precision(10);
    cout << fixed << ((double) S) * 2 / ((double) L) << '\n';
    return 0;
}