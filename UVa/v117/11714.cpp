#include<stdio.h>

#define LL int

LL make(int n)
{
	if(n==2)
		return 1;
	if(n%2)
	{
		LL ret=make(n+1);
		return ret-1;
	}
	else
	{
		LL ret=(n/2)+make(n/2)+1;
		return ret;
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
		printf("%d\n",make(n));
	return 0;
}
