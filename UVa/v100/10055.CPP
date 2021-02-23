#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
void main()
{
	long long m,n;
	while(scanf("%lld%lld",&m,&n)==2)
	{
		if(m>=n)printf("%lld\n",m-n);
		else printf("%lld\n",n-m);
	}
}













