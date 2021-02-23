#include<stdio.h>
#include<string.h>

#define LL long long

LL dp[505][505][2][2];

LL make(int remr,int remo,int prev,int st)
{
	if(remr+remo==1)
	{
		if(remr)
			return 1;
		if(remo)
			return (!st && !prev);
	}
	if(dp[remr][remo][prev][st]!=-1)
		return dp[remr][remo][prev][st];
	dp[remr][remo][prev][st] = 0;
	if(remr)
		dp[remr][remo][prev][st] += make(remr-1,remo,0,st);
	if(remo && !prev)
		dp[remr][remo][prev][st] += make(remr,remo-1,1,st);
	return dp[remr][remo][prev][st];
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int cs=0,n;
	while(scanf("%d",&n)==1 && n)
	{
		int nr = n/2 + 2 , nc = n/2 - 2;
		LL ans = make(nr-1,nc,0,0);
		if(nc)
			ans += make(nr,nc-1,1,1);
		if(n%2 || n<4)
			ans = 0;
		printf("Case %d: %lld\n",++cs,ans);
	}
	return 0;
}