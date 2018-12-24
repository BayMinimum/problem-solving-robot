#include<iostream>
#include<cstring>
using namespace std;
#define MAX_N 50

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char T[MAX_N+1], S[MAX_N+1];
    cin >> T;
    int N = strlen(T);
    if(N % 2 == 0){
        for(int i=N/2-1;i>=0;--i){
            cout << T[i] << T[N-i-1];
        }
    } else {
        cout << T[N/2];
        for(int i=N/2+1;i<N;++i){
            cout << T[i] << T[N-i-1];
        }
    }
    cout << '\n';
    return 0;
}