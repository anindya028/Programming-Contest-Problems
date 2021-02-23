#pragma warning (disable:4996)
#include<stdio.h>
#include<string.h>

int dp[50][50];
char s[50];

int make(int st,int nd)
{
	int i,j;
	if(st>nd)
		return 1;
	if(dp[st][nd]!=-1)
		return dp[st][nd];
	dp[st][nd]=0;
	int ok=(s[st]=='R');
	for(i=st+1;i<nd;i+=3)
	{
		ok+=(s[i]=='R');
		for(j=i+1;j<=nd;j+=3)
		{
			ok+=(s[j]=='R');
			if(ok<=1)
				dp[st][nd]+=(make(st+1,i-1)*make(i+1,j-1)*make(j+1,nd));
			ok-=(s[j]=='R');
		}
		ok-=(s[i]=='R');
	}
	return dp[st][nd];
}

int main()
{
	int n,t,cs;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%s",&n,s);
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %d\n",cs+1,make(0,n-1));
	}
	return 0;
}