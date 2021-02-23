#include<stdio.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))

char dp[50][50][50][50];

char make(int m,int n,int r,int c)
{
	if(m*n==1)
		return 0;
	if(dp[m][n][r][c]!=-1)
		return dp[m][n][r][c];

	dp[m][n][r][c]=0;
	int i;

	for(i=1;i<=r;i++)
		if(!make(m-i,n,r-i,c))
			dp[m][n][r][c]=1;
	for(;i<m;i++)
		if(!make(i,n,r,c))
			dp[m][n][r][c]=1;

	for(i=1;i<=c;i++)
		if(!make(m,n-i,r,c-i))
			dp[m][n][r][c]=1;
	for(;i<n;i++)
		if(!make(m,i,r,c))
			dp[m][n][r][c]=1;

	return dp[m][n][r][c];
}

int main()
{
	int t,n,m,r,c;
	mem(dp,-1);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&m,&n,&r,&c);
		if(make(m,n,r,c))
			printf("Gretel\n");
		else
			printf("Hansel\n");
	}
	return 0;
}