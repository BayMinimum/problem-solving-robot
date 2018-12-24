#include<iostream>
using namespace std;

int solve(int N, int K){
    int d = 0;
    while(++d){
        if((N % d == 0) && (N / d < K)) return d;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    int S = solve(N, K);
    cout << K * S + N / S << '\n';
    return 0;
}