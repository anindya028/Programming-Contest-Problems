#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct edge
{
	int source,dest;
	int cost;
}e[200005];

int parent[200005],rank[200005];

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

int main()
{
	int n,m,i,tot,sum,u,v;
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		for(i=tot=0;i<m;i++)
			scanf("%d%d%d",&e[i].source,&e[i].dest,&e[i].cost),tot+=e[i].cost;
		for(i=0;i<n;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
		//Minimum spaning tree
		sort(e,e+m);
		for(i=sum=0;i<m;i++)
		{
			u=find_set(e[i].source);
			v=find_set(e[i].dest);
			if(u!=v)
			{
				sum+=e[i].cost;
				link(u,v);
			}
		}
		printf("%d\n",tot-sum);
	}
	return 0;
}