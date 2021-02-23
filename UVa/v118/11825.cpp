#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))

vector<int> adj[20];

int memo[1<<17],dp[1<<17],n;

int make(int now)
{
	if(!now)
		return 0;
	if(dp[now]!=-1)
		return dp[now];
	dp[now]=0;
	int i,j;
	for(i=now;i;i=(i-1)&now)
		j=memo[i]+make(now ^ i),
		dp[now]=Max(dp[now],j);
	return dp[now];
}

int main()
{
	int i,cs=0,j,m,k;
	while(scanf("%d",&n)==1 && n)
	{
		memset(memo,0,sizeof(memo));
		memset(dp,-1,sizeof(dp));
		for(i=0;i<n;i++)
		{
			adj[i].clear();
			scanf("%d",&m);
			for(j=0;j<m;j++)
				scanf("%d",&k),adj[i].push_back(k);
		}
		for(i=1;i<(1<<n);i++)
		{
			int ok[20]={0};
			for(j=0;j<n;j++)
				if(i & 1<<j)
				{
					ok[j]=1;
					for(k=0;k<adj[j].size();k++)
						ok[adj[j][k]]=1;
				}
			k=0;
			for(j=0;j<n;j++)
				k+=ok[j];
			if(k==n)
				memo[i]=1;
		}
		printf("Case %d: %d\n",++cs,make((1<<n)-1));
	}
	return 0;
}