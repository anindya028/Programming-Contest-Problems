#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

vector<int> adj[102];
int dest;
int dp[102][505];

int make(int now,int rem)
{
	if(!rem)
		return now==dest;
	if(dp[now][rem]!=-1)
		return dp[now][rem];

	dp[now][rem]=0;
	int i;
	for(i=0;i<adj[now].size();i++)
		if(make(adj[now][i],rem-1))
			dp[now][rem]=1;
	return dp[now][rem];
}

int main()
{
	int n,m,d,s,i,u,v;
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		for(i=1;i<=n;i++)
			adj[i].clear();
		for(i=0;i<m;i++)
			scanf("%d%d",&u,&v),
			adj[u].push_back(v),
			adj[v].push_back(u);
		scanf("%d%d%d",&s,&dest,&d);
		mem(dp,-1);
		if(make(s,d))
			printf("Yes, Teobaldo can travel.\n");
		else
			printf("No, Teobaldo can not travel.\n");
	}
	return 0;
}

