#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
#define eps 1e-12
#define myabs(a) ((a>0)?(a):-(a))
#define inf 100000000.
#define Max(a,b) ((a>b)?(a):(b))
struct EDGE
{
	int source;
	int dest;
	double temp,weight;
}edge[20005];
int parent[105];
double bellmanford1(int nodenum,int edgenum,int s,int t)
{
	double *dist,temp;
	int i,j;
	dist=(double *)calloc(nodenum+1,sizeof(double));
	for(i=1;i<=nodenum;i++)
		dist[i]=inf;
	dist[s]=0;
	for(i=0;i<nodenum;i++)
		for(j=0;j<edgenum;j++)
			if(dist[edge[j].source]<inf)
			{
				if(Max(dist[edge[j].source],edge[j].temp)<dist[edge[j].dest])
					dist[edge[j].dest]=Max(dist[edge[j].source],edge[j].temp);
			}
	temp=dist[t];
	free(dist);
	return temp;
}
double bellmanford2(int nodenum,int edgenum,int s,int t,double mintemp)
{
	double *dist,temp;
	int i,j;
	dist=(double *)calloc(nodenum+1,sizeof(double));
	for(i=1;i<=nodenum;i++)
	{
		dist[i]=inf;
		parent[i]=i;
	}
	dist[s]=0;
	for(i=0;i<nodenum;i++)
		for(j=0;j<edgenum;j++)
			if(dist[edge[j].source]<inf && (edge[j].temp<mintemp || myabs(edge[j].temp-mintemp)<eps))
			{
				if((dist[edge[j].source]+edge[j].weight)<dist[edge[j].dest])
				{
					dist[edge[j].dest]=dist[edge[j].source]+edge[j].weight;
					parent[edge[j].dest]=edge[j].source;
				}
			}
	temp=dist[t];
	free(dist);
	return temp;
}
int main()
{
	double r,d,mintemp,mindist;
	int i,j,k,n,m,s,t,cur[105],l;
	while(scanf("%d%d",&n,&m)==2)
	{
		scanf("%d%d",&s,&t);
		for(i=l=0;i<m;i++)
		{
			scanf("%d%d%lf%lf",&j,&k,&r,&d);
			edge[l].source=j;
			edge[l].dest=k;
			edge[l].temp=r;
			edge[l].weight=d;
			l++;
			edge[l].source=k;
			edge[l].dest=j;
			edge[l].temp=r;
			edge[l].weight=d;
			l++;
		}
		mintemp=bellmanford1(n,2*m,s,t);
		mindist=bellmanford2(n,2*m,s,t,mintemp);
		j=t;
		cur[0]=t;
		for(i=1;parent[j]!=j;i++)
		{
			cur[i]=parent[j];
			j=cur[i];
		}
		printf("%d",cur[i-1]);
		for(j=i-2;j>=0;j--)
			printf(" %d",cur[j]);
		printf("\n%.1lf %.1lf\n",mindist,mintemp);
	}
	return 0;
}













