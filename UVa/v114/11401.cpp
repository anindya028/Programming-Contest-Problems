//Math/Combinatorics
#include<stdio.h>

#define SIZE 1000009

long long res[SIZE],temp;

void gen(){
	int i,x;

	for(i=0;i<=3;i++) res[i]=0;
	res[4]=1;
	res[5]=3;

	temp=2;
	for(i=6;i<SIZE-5;i++){
		x=i-3;
		if(x%2){
			temp+=(x/2)+1;
		}
		else temp+=x/2;
		res[i]=res[i-1]+temp;
	}
}

int main(){
	int n;

	gen();

	while(scanf("%d",&n) && n>=3){
		printf("%lld\n",res[n]);
	}

	return 0;
}