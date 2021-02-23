#include<stdio.h>
#include<string.h>

#define mod 10056

int ncr[1005][1005];
int calc(int n,int r)
{
	if(r==0 || n==r)
		return 1;
	if(ncr[n][r]!=-1)
		return ncr[n][r];
	ncr[n][r] = (calc(n-1,r) + calc(n-1,r-1))%mod;
	return ncr[n][r];
}
int dp[1005];
int make(int n)
{
	if(n<=1)
		return 1;
	if(dp[n]!=-1)
		return dp[n];
	dp[n] = 0;
	int i;
	for(i=1;i<=n;i++)
		dp[n] = (dp[n] + calc(n,i)*make(n-i))%mod;
	return dp[n];
}

int main()
{
	int t,n,cs=0;
	memset(dp,-1,sizeof(dp));
	memset(ncr,-1,sizeof(ncr));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("Case %d: %d\n",++cs,make(n));
	}
	return 0;
}