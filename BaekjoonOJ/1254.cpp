#include<cstdio>
#include<cstring>

#define MAX_LEN 1000
char S[MAX_LEN]; // string given as input
bool P[MAX_LEN][MAX_LEN]; // is interval a palindrome?

int main(){
  scanf("%s", S);
  int L = strlen(S);
  for(int i=0;i<L;i++) for(int j=0;j<L;j++) P[i][j] = false;
  for(int i=0;i<L;i++) P[i][i] = true;
  for(int i=0;i<L-1;i++){
    if(S[i] == S[i+1]) P[i][i+1] = true;
  }
  for(int t=2;t<L;t++){
    for(int i=0;i<L-t;i++){
      if(S[i] == S[i+t] && P[i+1][i+t-1]) P[i][i+t] = true;
    }
  }
  int i = 0;
  while(!P[i][L-1]) i++;
  printf("%d\n", L+i);
  return 0;
}
