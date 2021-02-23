#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

#define maxv 1005
#define inf 2100000000

struct node
{
	int dest,cost;
}x;

list<node> adj[maxv];

int mat[maxv][maxv],dist[maxv],n,ct[maxv];

int f(int u)
{
	int cnt=0,v;
	
	if(ct[u]>=0)
		return ct[u];
	for(v=1;v<=n;v++)
		if(mat[u][v]<inf && dist[u]>dist[v])
			cnt+=f(v);
	ct[u]=cnt;
	return cnt;
}



int main()
{
	int i,u,v,c,m,pos,mn,j;
	bool visited[maxv];
	list<node>::iterator iter;
	//freopen("k.txt","w",stdout);
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		for(i=1;i<=n;i++)
		{
			ct[i]=-1;
			dist[i]=inf;
			visited[i]=false;
			adj[i].clear();
			for(j=1;j<=n;j++)
				mat[i][j]=inf;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			if(mat[u][v]!=inf || c>1000000)
			{
				continue;
				//while(1)
					//printf("<>>>>>>>>><<<<\n");
			}
			mat[u][v]=mat[v][u]=c;
			x.dest=v;
			x.cost=c;
			adj[u].push_back(x);
			x.dest=u;
			adj[v].push_back(x);
		}
		dist[2]=0;
		ct[2]=1;
		while(true)
		{
			mn=inf;
			for(i=1;i<=n;i++)
				if(!visited[i] && dist[i]<mn)
				{
					pos=i;
					mn=dist[i];
				}
			if(mn==inf)
				break;
			visited[pos]=true;
			for(iter=adj[pos].begin();iter!=adj[pos].end();iter++)
			{
				if( (dist[pos]+iter->cost) < dist[iter->dest] )
					dist[iter->dest]=dist[pos]+iter->cost;
			}
		}
		printf("%d\n",f(1));
	}
	return 0;
}

