#include<stdio.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))

int dp[50][50][50][2],n,k;

int make(int x,int y,int rem,int prev)
{
	if(y<0)
		return 0;
	if(x==2*n)
	{
		if(!y)
			return !rem;
		else
			return 0;
	}
	if(dp[x][y][rem][prev]!=-1)
		return dp[x][y][rem][prev];
	if(y==k && prev)
		dp[x][y][rem][prev]=make(x+1,y+1,rem,1)+make(x+1,y-1,rem-1,0);
	else
		dp[x][y][rem][prev]=make(x+1,y+1,rem,1)+make(x+1,y-1,rem,0);
	return dp[x][y][rem][prev];
}

int main()
{
	int r;
	while(scanf("%d%d%d",&n,&r,&k)==3)
	{
		mem(dp,-1);
		printf("%d\n",make(1,1,r,1));
	}
	return 0;
}