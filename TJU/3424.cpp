#include<stdio.h>

#define LL long long

LL data[100000];

#define mod 1000003

LL powmod(LL a,LL p)
{
	if(!p)
		return 1;
	if(p%2)
	{
		LL b=powmod(a,p-1);
		return (a*b)%mod;
	}
	else
	{
		LL b=powmod(a,p/2);
		return (b*b)%mod;
	}
}

int main()
{
	int t,cs,i,n;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&data[i]);
		LL sum=0;
		for(i=0;i<n;i++)
			sum=(sum + powmod(2,data[i]))%mod;
		sum=( sum * powmod(n,mod-2) )%mod;
		printf("Case %d:%lld\n",cs+1,sum);
	}
	return 0;
}