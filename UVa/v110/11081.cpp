//DP(n^3)
#include<stdio.h>
#include<string.h>

#define mem(a) memset(a,-1,sizeof(a))
#define mod 10007

char a[2][70],s[70];
int dp[65][65][65][2];

int make(int pos,int n0,int n1,int now)
{
	if(!s[pos])
		return 1;
	int he[]={n0,n1};
	if(!a[now][he[now]])
		return 0;
	if(dp[pos][n0][n1][now]!=-1)
		return dp[pos][n0][n1][now];
	dp[pos][n0][n1][now]=0;
	if(a[now][he[now]]==s[pos])
	{
		if(!now)
		{
			if(!s[pos+1])
				dp[pos][n0][n1][now]=(dp[pos][n0][n1][now] + make(pos+1,n0+1,n1,0)) %mod;
			else
				dp[pos][n0][n1][now]=(dp[pos][n0][n1][now] + make(pos+1,n0+1,n1,0) + make(pos+1,n0+1,n1,1)) % mod;
		}
		else
		{
			if(!s[pos+1])
				dp[pos][n0][n1][now]=(dp[pos][n0][n1][now] + make(pos+1,n0,n1+1,1)) %mod;
			else
				dp[pos][n0][n1][now]=(dp[pos][n0][n1][now] + make(pos+1,n0,n1+1,0) + make(pos+1,n0,n1+1,1)) % mod;
		}
	}
	if(!now)
		dp[pos][n0][n1][now]=(dp[pos][n0][n1][now] + make(pos,n0+1,n1,0)) %mod;
	else
		dp[pos][n0][n1][now]=(dp[pos][n0][n1][now] + make(pos,n0,n1+1,1)) %mod;
	return dp[pos][n0][n1][now];
}

int main()
{
	int t,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s",a[0],a[1],s);
		mem(dp);	
		ans=( make(0,0,0,0) + make(0,0,0,1))%mod;
		printf("%d\n",ans);
	}
	return 0;
}