#include<cstdio>
#define MAX_D 2000
#define min(a, b) (a>b ? b : a)
int D1, D2;
int C[MAX_D+1];
int R;

int main(){
	scanf("%d %d", &D1, &D2);
	C[1] = 0;
	C[2] = 1;
	C[3] = 2;
	for(int i=4;i<=D2;i++){
		R = i-1;
		for(int j=2;j<D2;j++){
			if(i%j == 0) R -= C[j];
		}
		C[i] = R;
	}
	R = 1;
	for(int i=D1;i<=D2;i++) R += C[i];
	for(int i=2;i<=min(D2/2, D1-1);i++){
		if(D1%i == 0 || D1/i < D2/i) R += C[i];
	}
	printf("%d\n", R);
	return 0;
	
}