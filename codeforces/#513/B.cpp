#include<cstdio>
long long N;

long long getA(){
    long long s = 9;
    while(s <= N){
        s = s*10 + 9;
    }
    return (s-9)/10;
}

long long S(long long A){
    long long ret = 0;
    while(A){
        ret += A%10;
        A /= 10;
    }
    return ret;
}

int main(){
    scanf("%lld", &N);
    long long A = getA();
    long long B = N - A;
    printf("%lld\n", S(A)+S(B));
    return 0;
}