#include<stdio.h>

#define eps 1e-9
#define Max(a,b) (((a)>(b))?(a):(b))

int dp[1000][2];
double rate[1000];

int main()
{
	int n,i;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%lf",&rate[i]);
		dp[0][0]=100000;
		dp[0][1]=0;
		for(i=1;i<=n;i++)
		{
			dp[i][0]=Max(dp[i-1][0],(int)(dp[i-1][1]*rate[i-1]*.97+eps));
			dp[i][1]=Max(dp[i-1][1],(int)((dp[i-1][0]/rate[i-1])*.97+eps));
		}
		printf("%01d.%02d\n",dp[n][0]/100,dp[n][0]%100);
	}
	return 0;
}