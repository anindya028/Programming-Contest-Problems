#include<stdio.h>

int mod;

int powmod(int a,int p)
{
	if(!p)
		return 1;
	if(p%2)
	{
		int b=powmod(a,p-1);
		return (b*a)%mod;
	}
	else
	{
		int b=powmod(a,p/2);
		return (b*b)%mod;
	}
}

int main()
{
	int data[1005],n,t,cs,i,ans,k;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d%d",&n,&k,&mod);
		ans=0;
		for(i=0;i<n;i++)
			scanf("%d",&data[i]),data[i]%=mod,ans=(ans+data[i])%mod;
		ans=(ans * powmod(n%mod,k-1))%mod;
		ans=( ans * (k%mod))%mod;
		printf("Case %d: %d\n",cs+1,ans);
	}
	return 0;
}