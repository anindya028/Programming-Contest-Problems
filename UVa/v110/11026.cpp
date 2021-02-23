#include<stdio.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long

LL dp[1005][1005];
int num[1005],n,m;

LL make(int pos,int k)
{
	if(n-pos<k)
		return 0;
	if(dp[pos][k]!=-1)
		return dp[pos][k];

	dp[pos][k]= (num[pos] * make(pos+1,k-1))%m;
	
	dp[pos][k]= (dp[pos][k] + make(pos+1,k))%m;

	return dp[pos][k];
}

int main()
{
	int i;
	LL mx,now;
	while(scanf("%d%d",&n,&m)==2 && n && m)
	{
		mem(dp,-1);
		for(i=0;i<n;i++)
			scanf("%d",&num[i]),dp[i][0]=1;
		dp[i][0]=1;
		
		mx=0;
		for(i=1;i<=n;i++)
		{
			now=make(0,i);
			if(now>mx)
				mx=now;
		}
		printf("%lld\n",mx);
	}
	return 0;
}
