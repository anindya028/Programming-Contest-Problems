//06-Nov-07
//dijkstra->k-th shortest path
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;
#define INF 1<<29
struct node
{
	int dest,cost;
}x,temp;

int main()
{
	int n,i,j,pos,s,t,k,m,d[105][12],w,min,v,found;
	bool visited[105][12];//how many times a node is visited->maximum k times.
	list<node> adj[105];
	list<node>::iterator iter;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m)break;
		scanf("%d%d%d",&s,&t,&k);
		for(i=1;i<=n;i++)
		{
			adj[i].clear();
			for(j=1;j<=k;j++)
			{
				d[i][j]=INF;
				visited[i][j]=false;
			}

		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&j,&temp.dest,&temp.cost);
			adj[j].push_back(temp);
		}
        //dijkstra
		d[s][1]=0;
		while(1)
		{
			min=INF;
			found=0;
			for(i=1;i<=n;i++)
				for(j=1;j<=k;j++)
					if(!visited[i][j])
						if(d[i][j]<min)
						{
							min=d[i][j];
							pos=i;
							v=j;
						}

			if(min==INF)break;
			visited[pos][v]=true;
			for(iter=adj[pos].begin();iter!=adj[pos].end();iter++)
			{
				w=min+iter->cost;
				v=iter->dest;
				for(j=k;j>=1;j--)
				{
					if(w>d[v][j])break;
					if(w<d[v][j])
					{
						d[v][j+1]=d[v][j];
						d[v][j]=w;
					}
				}
			}
		}
		//end of dijkstra.
		if(d[t][k]>=INF || t>n || s>n)printf("-1\n");
		else printf("%d\n",d[t][k]);
	}
	return 0;
}

