#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_N 1500
#define ALPH 26

struct Count{
    short s[ALPH];
    bool operator < (const Count &c) const {
        for(int i=0;i<ALPH;i++){
            if(s[i] != c.s[i]) return s[i] < c.s[i];
        }
        return false;
    }
    bool operator == (const Count &c) const {
        for(int i=0;i<ALPH;i++){
            if(s[i] != c.s[i]) return false;
        }
        return true;
    }
    void init(){
        for(int i=0;i<ALPH;i++){
            s[i] = 0;
        }
    }
    void copy (const Count &c) {
        for(int i=0;i<ALPH;i++){
            s[i] = c.s[i];
        }
    }
};
Count C[MAX_N], D;
char *A, *B;
int N, M;

int solve(){
    for(int l=N;l>0;l--){
        C[0].init();
        for(int i=0;i<l;i++) C[0].s[B[i]-'a']++;
        for(int i=l;i<M;i++){
            C[i-l+1].copy(C[i-l]);
            C[i-l+1].s[B[i]-'a']++;
            C[i-l+1].s[B[i-l]-'a']--;
        }
        sort(C, C+M-l+1);
        D.init();
        for(int i=0;i<l;i++) D.s[A[i]-'a']++;
        if(binary_search(C, C+M-l+1, D)) return l;
        bool flag = false;
        for(int i=l;i<N;i++){
            D.s[A[i]-'a']++;
            D.s[A[i-l]-'a']--;
            if(binary_search(C, C+M-l+1, D)) return l;
        }
    }
    return 0;
}

int main(){
    char _A[MAX_N+1], _B[MAX_N+1];
    scanf("%s %s", _A, _B);
    A = _A;
    B = _B;
    N = strlen(A);
    M = strlen(B);
    if(N>M){
        char* temp = A;
        A = B;
        B = temp;
        int temp2 = N;
        N = M;
        M = temp2;
    }
    printf("%d\n", solve());
    return 0;
}