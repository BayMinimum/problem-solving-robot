#include<iostream>
using namespace std;
long long M;
int N;
int ans[60];

int main(){
    cin>>M>>N;
    for(int i=0;i<N;i++){
        cout<<M<<endl<<flush;
        cin>>ans[i];
        if(ans[i] == 0) return 0;
    }
    int i = N;
    long long fr = 1, to = M, md;
    while(fr < to){
        md = (fr + to) / 2;
        cout<<md<<endl<<flush;
        cin>>ans[i];
        ans[i] *= -ans[i%N];
        if(ans[i] == 0) return 0;
        else if(ans[i] > 0) fr = md + 1;
        else to = md - 1;
        i++;
    }
    cout<<fr<<endl<<flush;
    return 0;
}