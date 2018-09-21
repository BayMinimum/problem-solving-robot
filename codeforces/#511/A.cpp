#include<cstdio>
int t[][3] = {{1,1,1},{1,1,2},{1,2,2},{2,2,2},{1,2,4},{2,2,4},{2,2,5},{1,4,5},{1,5,5}};
int main(){
    int n;
    scanf("%d", &n);
    int m = (n - 3) % 9, r = ((n - 3) / 9) * 3;
    printf("%d %d %d\n", t[m][0] + r, t[m][1] + r, t[m][2] + r);
    return 0;
}