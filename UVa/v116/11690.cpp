#include<stdio.h>
#include<algorithm>

using namespace std;

struct edge
{
	int so,de;
}e[50005];

int parent[10005],rank[10005];
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

int cost[10005],sum[10005];

int main()
{
	int i,j,n,m,u,v,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",&cost[i]),
			parent[i]=i,
			rank[i]=sum[i]=0;
		for(i=0;i<m;i++)
			scanf("%d%d",&e[i].so,&e[i].de);
		for(i=0;i<m;i++)
		{
			u=find_set(e[i].so);
			v=find_set(e[i].de);
			if(u!=v)
				link(u,v);
		}
		for(i=0;i<n;i++)
			sum[find_set(i)]+=cost[i];
		j=1;
		for(i=0;i<n;i++)
			if(sum[i])
				j=0;
		if(j)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
