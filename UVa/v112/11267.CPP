#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;

#define Max 205
int parent[Max],rank[Max],col[Max];
bool adj[Max][Max];
struct edge
{
	int source,dest;
	double cost;
}e[Max*Max];

///path-compression
void link(int a,int b)
{
	if(rank[a]>rank[b])
		parent[b]=a;
	else
	{
		parent[a]=b;
		if(rank[a]==rank[b])
			rank[b]=rank[b]+1;
	}
	return;
}
////finding the root of set
int find_set(int a)
{
	if(a!=parent[a])
		parent[a]=find_set(parent[a]);
	return parent[a];
}
//sorting edges in increasing order
bool operator<(edge a,edge b)
{
	return a.cost<b.cost;
}
//checks whether bicolorable or not
bool bic(int n)
{
	int i,j;
	queue<int> q;

	col[1]=1;
	q.push(1);
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		for(j=i+1;j<=n;j++)
		{			
			if(adj[i][j])
			{
				if(col[i]!=col[j])
				{
					if(col[i]==1)
						col[j]=2;
					else
						col[j]=1;
					q.push(j);
				}
				else
					return false;
			}
		}
	}
	return true;
}

int main()
{
	int n,m,a,b,c,u,v,i,j,sum;
	edge mst[Max*Max];
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				adj[i][j]=false;
			col[i]=0;
			parent[i]=i;
			rank[i]=0;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			adj[a][b]=adj[b][a]=true;
			e[i].source=a;
			e[i].dest=b;
			e[i].cost=c;
		}
		if(!bic(n))
		{
			printf("Invalid data, Idiot!\n");
			continue;
		}
		sort(e,e+m);
		for(i=j=0;i<m;i++)
		{
			u=find_set(e[i].source);
			v=find_set(e[i].dest);
			if(u!=v || e[i].cost<0)
			{
				mst[j]=e[i];
				j++;
				if(u!=v)
					link(u,v);
			}
		}
		
		for(i=sum=0;i<j;i++)
			sum+=mst[i].cost;
		printf("%d\n",sum);
	}
	return 0;
}













