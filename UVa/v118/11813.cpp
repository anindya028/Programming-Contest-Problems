#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define Min(a,b) (((a)<(b))?(a):(b))
#define SZ 100005
#define pii pair<int,int>

int n,m,b;
int st[14];
vector< pii > adj[SZ];
int dist[SZ],vis[SZ];

int mat[15][15];

void dijkstra(int so)
{
	int i;
	memset(vis,0,sizeof(vis));
	for(i=0;i<n;i++)
		dist[i]=1<<29;
	dist[st[so]]=0;
	priority_queue< pii > pq;
	pq.push(make_pair(0,st[so]));
	while(!pq.empty())
	{
		pii u=pq.top();
		pq.pop();

		if(vis[u.second])
			continue;
		vis[u.second]=1;
		
		for(i=0;i<adj[u.second].size();i++)
			if(dist[u.second]-adj[u.second][i].first<dist[adj[u.second][i].second])
				dist[adj[u.second][i].second]=dist[u.second]-adj[u.second][i].first,
				pq.push(make_pair(-dist[adj[u.second][i].second],adj[u.second][i].second));
	}
	for(i=0;i<b;i++)
		mat[so][i]=dist[st[i]];
}

int dp[12][1<<12];
int make(int pos,int now)
{
	if(now==((1<<b)-1))
		return mat[pos][0];
	if(dp[pos][now]!=-1)
		return dp[pos][now];
	dp[pos][now]=1<<29;
	int i,j;
	for(i=0;i<b;i++)
		if(!(now & 1<<i))
			j=mat[pos][i]+make(i,now | 1<<i),
			dp[pos][now]=Min(dp[pos][now],j);
	return dp[pos][now];
}

int main()
{
	int t,i,u,v,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			adj[i].clear();
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			adj[u].push_back(make_pair(-c,v));
			adj[v].push_back(make_pair(-c,u));
		}
		scanf("%d",&b);
		b++;
		st[0]=0;
		for(i=1;i<b;i++)
			scanf("%d",&st[i]);
		for(i=0;i<b;i++)
			dijkstra(i);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",make(0,1));
	}
	return 0;
}	