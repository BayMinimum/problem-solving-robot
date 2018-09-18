#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX_C 100000
int N;
int A, B, C, AB, BC, CA, ABC;

int main(){
    cin>>N;
    A = B = C = AB = BC = CA = ABC = MAX_C + 1;
    int c, l;
    char vit[4];
    bool fill[3];
    for(int i=0;i<N;++i){
        cin>>c>>vit;
        fill[0] = fill[1] = fill[2] = false;
        l = strlen(vit);
        for(int j=0;j<l;++j) fill[vit[j] - 'A'] = true;
        if(fill[0]){
            if(fill[1]){
                if(fill[2]) ABC = min(ABC, c);
                else AB = min(AB, c);
            } else if(fill[2]) CA = min(CA, c);
            else A = min(A, c);
        } else if(fill[1]){
            if(fill[2]) BC = min(BC, c);
            else B = min(B, c);
        } else if(fill[2]) C = min(C, c);
    }
    c = min({A + B + C, AB + C, BC + A, CA + B, AB + BC, BC + CA, CA + AB, ABC});
    cout<<(c > MAX_C ? -1 : c)<<endl;
    return 0;
}