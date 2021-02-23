#include<stdio.h>

#define inf (1<<29)
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))

int x,y,z;

int dp[1005][2];

int make(int n,int egg)
{
	if(n==1)
		return egg*(-x/2);
	if(dp[n][egg]!=inf)
		return dp[n][egg];
	int i,a,b;
	for(i=1;i<n;i++)
	{
		a=make(i,0);
		b=make(n-i,1);
		dp[n][egg]=Min(dp[n][egg],Max(a,b));
	}
	if(!egg)
		dp[n][egg]+=(x+y);
	else
		dp[n][egg]+=z;
	return dp[n][egg];
}

int main()
{
	int n,t,cs,i;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d%d%d",&n,&x,&y,&z);
		for(i=0;i<=n;i++)
			dp[i][0]=dp[i][1]=inf;
		printf("Case %d: %d\n",cs+1,make(n,0));
	}
	return 0;
}