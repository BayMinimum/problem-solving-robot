#include<cstdio>
#define MAX_N 500000

int N;
struct Runner{
    int p, i;
    bool operator < (const Runner &r) const {
        return p < r.p;
    }
};
Runner R[MAX_N], temp[MAX_N];
int S[MAX_N];

void sort(int lo, int hi){
    if(lo == hi) return;
    int md = (lo + hi) / 2;
    sort(lo, md);
    sort(md+1, hi);
    int l = lo, h = md + 1, i = 0;
    while(l <= md && h <= hi){
        if(R[l] < R[h]) temp[i++] = R[l++];
        else{
            temp[i] = R[h++];
            S[temp[i++].i] += md - l + 1;
        }
    }
    while(l <= md){
        temp[i++] = R[l++];
    }
    while(h <= hi){
        temp[i++] = R[h++];
    }
    for(int j=0;j<i;j++){
        R[lo + j] = temp[j];
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &(R[i].p));
        R[i].i = i;
        S[i] = 1;
    }
    sort(0, N-1);
    for(int i=0;i<N;i++){
        printf("%d\n", S[i]);
    }
    return 0;
}