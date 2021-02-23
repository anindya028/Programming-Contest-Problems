#include<stdio.h>
#include<string.h>

#define LL long long 

LL dp[35][35][104];
int k;

LL make(int one,int zero,int mod)
{
	if(!one && !zero)
		return !mod;
	if(dp[one][zero][mod]!=-1)
		return dp[one][zero][mod];
	dp[one][zero][mod]=0;
	if(one)
		dp[one][zero][mod]+=make(one-1,zero,(mod*2+1)%k);
	if(zero)
		dp[one][zero][mod]+=make(one,zero-1,(mod*2)%k);
	return dp[one][zero][mod];
}

int main()
{
	int n,t,cs;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&k);
		memset(dp,-1,sizeof(dp));
		if(n%2 || !k)
		{
			printf("Case %d: 0\n",cs+1);
			continue;
		}
		//if(!k)
		//	k++;
		printf("Case %d: %lld\n",cs+1,make(n/2-1,n/2,(1%k)));
	}
	return 0;
}