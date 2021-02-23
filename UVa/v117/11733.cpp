#include<stdio.h>
#include<algorithm>

using namespace std;

int parent[10005],rank[10005];

struct edge
{
	int source,dest;
	int cost;
}e[200005];

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
	if(a.cost==b.cost)
		return a.source<b.source;
	return a.cost<b.cost;
}

int main()
{
	int n,m,a,t,cs,i,ans,tot;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d%d",&n,&m,&a);
		int j=0;
		for(i=1;i<=n;i++)
		{
			e[j].source=0,e[j].dest=i,e[j].cost=a;
			j++;
		}
		for(i=0;i<m;i++)
			scanf("%d%d%d",&e[j].source,&e[j].dest,&e[j].cost),j++;
		//initialization
		for(i=0;i<=n;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
		//Minimum spaning tree
		sort(e,e+j);
		ans=tot=0;
		for(i=0;i<j;i++)
		{
			int u=find_set(e[i].source),v=find_set(e[i].dest);
			if(u!=v)
				link(u,v),
				ans+=e[i].cost,
				tot+=(!e[i].source);
		}
		printf("Case #%d: %d %d\n",cs+1,ans,tot);
	}
	return 0;
}