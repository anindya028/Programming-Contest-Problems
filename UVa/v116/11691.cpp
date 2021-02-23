#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define Min(a,b) (((a)<(b))?(a):(b))

char ok[1<<20][8];
char dp[1<<20][8];
int fr[8],sum[8],g[8],cs;

int make(int now,int rem)
{
	if(now==((1<<sum[7])-1))
		return rem;
	if(ok[now][rem]==cs)
		return dp[now][rem];
	int i,j;
	ok[now][rem]=cs;
	dp[now][rem]=120;
	for(i=2;i<8;i++)
	if(g[i]<fr[i])
	{
		g[i]++;
		if(rem<=1)
			j=rem+make(now | 1<<(sum[i-1]+g[i]-1),i);
		else if(rem>=i)
			j=rem+make(now | 1<<(sum[i-1]+g[i]-1),1);
		else
			j=rem+make(now | 1<<(sum[i-1]+g[i]-1),i-(rem-1));
		g[i]--;
		dp[now][rem]=Min(dp[now][rem],j);
	}
	return dp[now][rem];
}

int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	cs=0;
	while(t--)
	{
		cs++;
		scanf("%d",&n);
		memset(fr,0,sizeof(fr));
	
		for(i=0;i<n;i++)
			scanf("%d",&j),fr[j]++;
		sum[1]=0;
		for(i=2;i<8;i++)
			sum[i]=sum[i-1]+fr[i];
		
	//	memset(dp,-1,sizeof(dp));
		int ans=fr[1]+make(0,0);

		printf("%d\n",ans);
	}
	return 0;
}