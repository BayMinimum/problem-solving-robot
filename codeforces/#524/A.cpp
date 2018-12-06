#include<cstdio>
int n, k;

int main(){
    scanf("%d %d", &n, &k);
    int r = (2 * n + k - 1) / k;
    int g = (5 * n + k - 1) / k;
    int b = (8 * n + k - 1) / k;
    printf("%d\n", r + g + b);
    return 0;
}