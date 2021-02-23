#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

#define LL long long
#define pii pair<int,int>
#define Max(a,b) ((a)>(b)?(a):(b))

struct edge
{
	int uu,vv,c;
}e[100005];

vector< pii > adj[2][10005];
int vis[2][10005],n;
LL dist[2][10005];

void dijkstra(int s,int is)
{
	int i;
	LL inf = 1<<28;
	inf *= inf;
	memset(vis[is],0,sizeof(vis[is]));
	for(i=1;i<=n;i++)
		dist[is][i] = inf;
	dist[is][s] = 0;
	priority_queue< pii > q;
	q.push( pii(0,s) );
	pii u,v;
	
	while(!q.empty())
	{
		u = q.top();
		q.pop();

		if(vis[is][u.second])
			continue;
		vis[is][u.second] = 1;
		int now = u.second;
		for(i = 0; i < adj[is][now].size();i++)
		{
			int cost = -u.first + adj[is][now][i].first;
			if(cost < dist[is][adj[is][now][i].second])
			{
				dist[is][adj[is][now][i].second] = cost;
				v.first = -cost;
				v.second = adj[is][now][i].second;
				q.push(v);
			}	
		}
	}
}

int main()
{
	int i,m,s,t,T,p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
		for(i=1;i<=n;i++)
			adj[0][i].clear(),adj[1][i].clear();

		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&e[i].uu,&e[i].vv,&e[i].c);
			adj[0][e[i].uu].push_back(pii(e[i].c,e[i].vv));
			adj[1][e[i].vv].push_back(pii(e[i].c,e[i].uu));
		}

		dijkstra(s,0);
		dijkstra(t,1);

		int ans = -1;
		for(i=0;i<m;i++)
			if(dist[0][e[i].uu] + dist[1][e[i].vv] + e[i].c <= p)
				ans = Max(ans,e[i].c);
		printf("%d\n",ans);
	}
	return 0;
}