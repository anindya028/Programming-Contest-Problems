//Dijkstra + Bellman-Ford
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define inf 1<<29
#define Min(a,b) ((a<b)?(a):(b)) 
struct EDGE
{
	int source;
	int dest;
	int weight;
}edge[105*105];
int bellmanford(int nodenum,int edgenum)
{
	int *dist,i,j;
	dist=(int *)calloc(nodenum+1,sizeof(int));
	for(i=1;i<=nodenum;i++)
		dist[i]=inf;
	dist[1]=0;
	for(i=0;i<nodenum;i++)
		for(j=0;j<edgenum;j++)
			if(dist[edge[j].source]!=inf)
			{
				if((dist[edge[j].source]+edge[j].weight)<dist[edge[j].dest])
					dist[edge[j].dest]=dist[edge[j].source]+edge[j].weight;
			}
	j=dist[nodenum];
	free(dist);
	return j;
}
int main()
{
	int mat[105][105],i,j,k,d[105],n,m,c,sum,visited[105],min,pos,parent[105];
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		scanf("%d",&m);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				mat[i][j]=inf;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&j,&k,&c);
			mat[k][j]=mat[j][k]=c;
		}
		for(i=1;i<=n;i++)
		{
			d[i]=inf;
			visited[i]=0;
			parent[i]=i;
		}
		d[1]=0;
		while(true)
		{
			min=inf;
			for(i=1;i<=n;i++)
				if(!visited[i])
					if(d[i]<min)
					{
						min=d[i];
						pos=i;
					}
			if(min==inf)break;
			visited[pos]=1;
			for(i=1;i<=n;i++)
				if(mat[pos][i]<inf)
					if((d[pos]+mat[pos][i])<d[i])
					{
						d[i]=d[pos]+mat[pos][i];
						parent[i]=pos;
					}
		}
		if(d[n]==inf)
		{
			printf("Back to jail\n");
			continue;
		}
		sum=d[n];
		pos=n;
		while(parent[pos]!=pos)
		{
			mat[pos][parent[pos]]=-mat[parent[pos]][pos];
			mat[parent[pos]][pos]=inf;
			pos=parent[pos];
		}
		for(i=1,k=0;i<=n;i++)
			for(j=1;j<=n;j++)
				if(mat[i][j]<inf)
				{
					edge[k].source=i;
					edge[k].dest=j;
					edge[k].weight=mat[i][j];
					k++;
				}
		d[n]=bellmanford(n,k);
		if(d[n]==inf)
		{
			printf("Back to jail\n");
			continue;
		}
		sum+=d[n];
		printf("%d\n",sum);
	}
	return 0;
}













