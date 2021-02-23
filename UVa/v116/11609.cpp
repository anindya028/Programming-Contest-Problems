#include<stdio.h>

#define LL long long
#define mod 1000000007

LL bigpow(LL a,LL p)
{
	LL now;
	if(!p)
		return 1;
	if(p%2==0)
	{
		now=bigpow(a,p/2);
		return (now*now)%mod;
	}
	else
	{
		now=bigpow(a,p-1);
		return (now*a)%mod;
	}
}

int main()
{
	int t,cs;
	LL n,ans;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%lld",&n);
		ans=bigpow((LL)2,n-1);
		ans=(ans*n)%mod;
		printf("Case #%d: %lld\n",cs+1,ans);
	}
	return 0;
}
