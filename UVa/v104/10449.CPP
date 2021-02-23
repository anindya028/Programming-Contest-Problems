#include<stdio.h>
//Belman-Ford  ,
//Very good graph problem
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 1<<30
struct Edge
{
	int source;
	int dest,weight;
}*edge;
int *dist;
void bellmanford(int nodenum,int edgenum)
{
	int i,j;
	dist=(int *)calloc(nodenum+1,sizeof(int));
	for(i=1;i<=nodenum;i++)
		dist[i]=inf;
	dist[1]=0;
	for(i=1;i<=nodenum;i++)
		for(j=0;j<edgenum;j++)
			if(dist[edge[j].source]!=inf)
			{
				if((dist[edge[j].source]+edge[j].weight)<dist[edge[j].dest])
					dist[edge[j].dest]=dist[edge[j].source]+edge[j].weight;
			}
	for(i=0;i<edgenum;i++)
	{
		if(dist[edge[i].dest]>(dist[edge[i].source]+edge[i].weight))
		{
			dist[edge[i].dest]=inf;		
		}
	}
	return;
}
void againbellmanford(int nodenum,int edgenum)
{
	int i,j;
	for(i=1;i<=nodenum;i++)
		for(j=0;j<edgenum;j++)
			if(dist[edge[j].source]==inf)
				dist[edge[j].dest]=inf;
	return;
}
int main()
{
	int cit[201];
	int i,n,r,cs=0,q,c;
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&cit[i]);
		scanf("%d",&r);
		if(r)edge=(Edge *)calloc(r,sizeof(Edge));
		for(i=0;i<r;i++)
		{
			scanf("%d%d",&edge[i].source,&edge[i].dest);
			edge[i].weight=(cit[edge[i].dest]-cit[edge[i].source])*(cit[edge[i].dest]-cit[edge[i].source])*(cit[edge[i].dest]-cit[edge[i].source]);
		}
		printf("Set #%d\n",++cs);
		if(n)
		{
			bellmanford(n,r);
			againbellmanford(n,r);
			scanf("%d",&q);
			for(i=0;i<q;i++)
			{
				scanf("%d",&c);
				if(c>n)printf("?\n");
				else if(dist[c]<3 || dist[c]>(1<<28))printf("?\n");
				else printf("%d\n",dist[c]);
			}
			free(dist);
		}
		else
		{
			scanf("%d",&q);
			for(i=0;i<q;i++)
			{
				scanf("%d",&c);
				printf("?\n");
			}
		}
		if(r)free(edge);
	}
	return 0;
}













