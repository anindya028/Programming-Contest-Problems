#include<stdio.h>

#define LL long long

LL sq[105],cu[105],fo[105];

int main()
{
	int n,i;
	sq[0]=cu[0]=fo[0]=0;
	for(i=1;i<=100;i++)
		sq[i]=sq[i-1]+i*i,
		cu[i]=cu[i-1]+i*i*i,
		fo[i]=fo[i-1]+i*i*i*i;
	while(scanf("%d",&n)==1)
	{
		LL m=(n*(n+1))/2;
		printf("%lld %lld %lld %lld %lld %lld\n",sq[n],m*m-sq[n],cu[n],m*m*m-cu[n],fo[n],m*m*m*m-fo[n]);
	}
	return 0;
}