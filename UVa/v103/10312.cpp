#include<stdio.h>

int main()
{
	long long cat[30],brack[30];
	int i,n;
	cat[0]=1;
	cat[1]=1;
	cat[2]=2;
	for(i=3;i<28;i++)
		cat[i]=(2*(2*i-1)*cat[i-1])/(i+1);
	brack[1]=1;
	brack[2]=1;
	for(i=3;i<29;i++)
		brack[i]=(3*(2*i-3)*brack[i-1]-(i-3)*brack[i-2])/i;
	while(scanf("%d",&n)==1)
		printf("%lld\n",brack[n]-cat[n-1]);
	return 0;
}