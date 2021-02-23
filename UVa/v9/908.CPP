#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
struct edge
{
	int source,dest,cost;
}e[1000050];
int rank[1000050],parent[1000050];

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

int find_set(int a)
{
	if(a!=parent[a])
		parent[a]=find_set(parent[a]);
	return parent[a];
}

bool operator<(edge a,edge b)
{
	return a.cost<b.cost;
}
int main()
{
	int i,j,k,cs=0,t,m,n,firstsum,secsum,u,v;
	while(scanf("%d",&n)==1)
	{
		if(cs)printf("\n");
		for(i=firstsum=0;i<n-1;i++)
		{
			scanf("%d%d%d",&e[i].source,&e[i].dest,&e[i].cost);
			firstsum+=e[i].cost;
		}
		scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d%d%d",&e[i].source,&e[i].dest,&e[i].cost);
			i++;
		}
		t=n-1+k;
		for(i=1;i<=n;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
		sort(e,e+t);
		for(i=secsum=0;i<t;i++)
		{
			u=find_set(e[i].source);
			v=find_set(e[i].dest);
			if(u!=v)
			{
				secsum+=e[i].cost;
				link(u,v);
			}
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d%d%d",&u,&v,&k);
		printf("%d\n%d\n",firstsum,secsum);
		cs++;
	}
	return 0;
}













