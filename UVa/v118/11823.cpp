#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))

vector<int> adj[305];
int dis[305],vis[305];

int dp[305][305];

int dp2[305];

int calc(int a)
{
	int i,j;
	if(dp2[a]!=-1)
		return dp2[a];
	dp2[a]=0;
	for(i=0;i<adj[a].size();i++)
		if(dis[adj[a][i]]<dis[a])
			j=1+calc(adj[a][i]),
			dp2[a]=Max(dp2[a],j);
	return dp2[a];
}

int make(int a,int b)
{
	if(dp[a][b]!=-1)
		return dp[a][b];
	dp[a][b]=0;
	int i,j;
	for(i=0;i<adj[a].size();i++)
		if(dis[adj[a][i]]<dis[a] && adj[a][i]!=b)
		{
			if(dis[adj[a][i]]>dis[b])
				j=1+make(adj[a][i],b),
				dp[a][b]=Max(dp[a][b],j);
			else
				j=1+make(b,adj[a][i]),
				dp[a][b]=Max(dp[a][b],j);
		}
	j=calc(b);
	dp[a][b]=Max(dp[a][b],j);
	
	return dp[a][b];
}

int tim;

void dfs(int now)
{
	tim++;
	vis[now]=1;
	int i;
	for(i=0;i<adj[now].size();i++)
		if(!vis[adj[now][i]])
			dfs(adj[now][i]);
	
	dis[now]=++tim;
	vis[now]=2;
}

int main()
{
	int i,n,m,a,b,t,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(dp,-1,sizeof(dp));
		memset(dp2,-1,sizeof(dp2));
		for(i=0;i<n;i++)
			adj[i].clear(),vis[i]=0;
		for(i=0;i<m;i++)
			scanf("%d%d",&a,&b),adj[a-1].push_back(b-1);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		tim=0;
		for(i=0;i<n;i++)
			if(!vis[i])
				dfs(i);

		int ans=0,now;
		for(i=0;i<n;i++)		
			for(j=0;j<n;j++)
				if(i!=j && dis[i]>dis[j])
					now=make(i,j),ans=Max(ans,2+now); 

		printf("%d\n",ans);
	}
	return 0;
}