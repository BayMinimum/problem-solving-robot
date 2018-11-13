#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_N 123456
int N;
long long ATK, MaxHP, mCurHP;
long long T, A, H;

int main(){
    scanf("%d %lld", &N, &ATK);
    for(int i=0;i<N;++i){
        scanf("%lld %lld %lld", &T, &A, &H);
        if(T == 1){
            int round = (H + ATK - 1) / ATK;
            mCurHP += (round - 1) * A;
            MaxHP = max(MaxHP, mCurHP + 1);
        } else{
            mCurHP -= H;
            if(mCurHP < 0) mCurHP = 0;
            ATK += A;
        }
    }
    printf("%lld\n", MaxHP);
    return 0;
}

