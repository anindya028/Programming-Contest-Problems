#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define myabs(a) (((a)>0)?(a):-(a))
#define inf 1<<29
#define Min(a,b) ((a<b)?a:b)
struct Edge
{
	int source,dest,weight;
	int lift;
}edge[200005];

void bellmanford(int nodenum,int edgenum,int d)
{
	int dist[105],i,j,li[105],c;
	for(i=0;i<=nodenum;i++)
	{
		dist[i]=inf;
		li[i]=0;
	}
	dist[0]=0;
	for(i=0;i<=nodenum;i++)
		for(j=0;j<edgenum;j++)
			if(dist[edge[j].source]<inf)
			{
				if(!li[edge[j].source])
				{
					dist[edge[j].dest]=Min(dist[edge[j].dest],dist[edge[j].source]+edge[j].weight);
					li[edge[j].source]=li[edge[j].dest]=edge[j].lift;
				}     
				else if(li[edge[j].source]==edge[j].lift)
				{   
					c=dist[edge[j].source]+edge[j].weight;
					if(c<dist[edge[j].dest])
					{
						dist[edge[j].dest]=c;
						li[edge[j].dest]=li[edge[j].source];
					}
				}
				else
				{
					c=dist[edge[j].source]+edge[j].weight;
					if((c+60)<dist[edge[j].dest])
					{
						dist[edge[j].dest]=c+60;
						li[edge[j].dest]=edge[j].lift;
					}
				}
			}
	if(dist[d]>=inf)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n",dist[d]);
	return;
}

int main()
{
	int n,t[10],i,k,j,cnt,f[105],s,bs,dbs,l,maxnode;
	char buf[1000];
	while(scanf("%d%d",&n,&s)==2)
	{
		for(i=1;i<=n;++i)
			scanf("%d",&t[i]);
		cnt=maxnode=0;
		gets(buf);
		for(i=1;i<=n;i++)
		{
			gets(buf);
			bs=dbs=j=0;
			while(sscanf(buf+bs,"%d%n",&f[j],&dbs)==1)
			{
				bs+=dbs;
				if(f[j]>maxnode)
					maxnode=f[j];
				j++;
			}
			for(k=0;k<j;k++)
				for(l=k+1;l<j;l++)
				{
					edge[cnt].source=f[k];
					edge[cnt].dest=f[l];
					edge[cnt].weight=myabs(f[l]-f[k])*t[i];
					edge[cnt].lift=i;
					cnt++;
					edge[cnt].source=f[l];
					edge[cnt].dest=f[k];
					edge[cnt].weight=myabs(f[l]-f[k])*t[i];
					edge[cnt].lift=i;
					cnt++;
				}

		}
		bellmanford(maxnode,cnt,s);
	}
	return 0;
 }



