#include<stdio.h>
#include<string.h>

#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))

int dp[1005][22];

int make(int n,int s)
{
	if(!s || n<2)
		return n;
	if(dp[n][s]!=-1)
		return dp[n][s];
	int i,j,k;
	dp[n][s]=1000000;
	for(i=1;i<=n;i++)
		j=1+make(i-1,s-1),k=1+make(n-i,s),
		dp[n][s]=Min(dp[n][s],Max(j,k));
	return dp[n][s];
}

int main()
{
	int t,n,s;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&s);
		printf("%d\n",make(n,s-1));
	}
	return 0;
}