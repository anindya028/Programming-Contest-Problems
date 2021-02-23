#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
#define Max 1005

int parent[Max],rank[Max];
struct edge
{
	int source,dest,cost;
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

int main()
{
	int i,j,k,m,n,t,u,v,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		j=0;
		for(i=0;i<m;++i)
			scanf("%d%d",&u,&v),e[j].source=u-1,e[j].dest=v-1,e[j].cost=0,j++;
		for(i=0;i<k;++i)
			scanf("%d%d%d",&u,&v,&d),e[j].source=u-1,e[j].dest=v-1,e[j].cost=d,j++;
		for(i=0;i<n;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
		sort(e,e+k+m);
		for(i=j=d=0;i<k+m;i++)
		{
			u=find_set(e[i].source);
			v=find_set(e[i].dest);
			if(u!=v)
				d+=e[i].cost,j++,link(u,v);
		}
		if(j!=(n-1))
			printf("-1\n");
		else
			printf("%d\n",d);
	}
	return 0;
}