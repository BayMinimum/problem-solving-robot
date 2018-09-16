#include<cstdio>
#include<algorithm>
using namespace std;
long long a, b, x, y;

long long gcd(long long n, long long m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main(){
    scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
    long long g = gcd(max(x, y), min(x, y));
    x /= g;
    y /= g;
    printf("%lld\n", min(a / x, b / y));
    return 0;
}