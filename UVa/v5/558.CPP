#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 20000000
struct EDGE
{
	int source;
	int dest;
	int weight;
}edge[2005];
bool bellmanford(int nodenum,int edgenum)
{
	int *dist,i,j;
	dist=(int *)calloc(nodenum,sizeof(int));
	for(i=0;i<nodenum;i++)
		dist[i]=inf;
	dist[0]=0;
	for(i=0;i<nodenum;i++)
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
			free(dist);
			return true;
		}
	}
	free(dist);
	return false;
}
int main()
{
	int cs,i,j,n,m;
	scanf("%d",&cs);
	for(i=0;i<cs;i++)
	{
		scanf("%d%d",&n,&m);
		for(j=0;j<m;j++)
			scanf("%d%d%d",&edge[j].source,&edge[j].dest,&edge[j].weight);
		if(bellmanford(n,m))printf("possible\n");
		else printf("not possible\n");
	}
	return 0;
}













