#include<cstdio>

int days(int month){
    if(month%2){
        if(month>=9) return 30;
        return 31;
    }
    if(month == 2) return 28;
    if(month >= 8) return 31;
    return 30;
}

int S[13];
char C[][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int x, y;

int main(){
    scanf("%d %d", &x, &y);
    for(int i=2;i<=12;++i) S[i] = S[i-1] + days(i-1);
    y += S[x];
    printf("%s\n", C[y%7]);
    return 0;
}