//Dijkstra O((E + V)*logV)
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define inf 1<<29
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)
#define MS 20005

struct node
{
	int dest,cost;
}x,y;

bool operator<(node a,node b)
{
	return a.cost>b.cost;
}

vector<node> adj[MS];//adjacency list
int dis[MS];
bool visited[MS];
priority_queue<node> pq;

int main()
{
	int n,T,s,t,m,u,v,c,cnt;
	register int i,cs;
	scanf("%d",&T);
	Foro(cs,T)
	{
		scanf("%d%d%d%d",&n,&m,&s,&t);
		//initialization
        Foro(i,n)
			adj[i].clear(),visited[i]=false,dis[i]=inf;
		while(!pq.empty())
			pq.pop();
		//input
		Foro(i,m)
		{
			scanf("%d%d%d",&u,&v,&c);
			x.dest=v;
			x.cost=c;
			adj[u].pb(x);
			x.dest=u;
			adj[v].pb(x);
		}
		//dijkstra
		dis[s]=0;
		x.cost=0;
		cnt=0;
		x.dest=s;
		pq.push(x);
		while(!pq.empty() && cnt<n)//this loop will run node times
		{
			y=pq.top();
			pq.pop();
			u=y.dest;
			if(visited[u])
				continue;
			visited[u]=1;
			cnt++;
			if(u==t)         //or may break earlier if target node is found
				break;
			Forc(i,adj[u])
			{
				x=adj[u][i];
				v=x.dest;
				if(dis[u]+x.cost<dis[v])
					dis[v]=dis[u]+x.cost,y.dest=v,y.cost=dis[v],pq.push(y);
			}
		}
		if(dis[t]==inf)
			printf("Case #%d: unreachable\n",cs+1);
		else
			printf("Case #%d: %d\n",cs+1,dis[t]);
	}
	return 0;
}