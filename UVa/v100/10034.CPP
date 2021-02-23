#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

#define Max 755

struct point            /////////////////node
{
	double x,y;
}p[Max];
int parent[Max],rank[Max];
struct edge
{
	int source,dest;
	double cost;
}e[Max*Max];

double Dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

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
	int cs,t,i,j,k,n,u,v;
	edge mst[Max-1];//stores all edges of mst
	double sum;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		if(cs)printf("\n");
		scanf("%d",&n);
		//Building the graph
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		for(i=k=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				e[k].source=i;
				e[k].dest=j;
				e[k].cost=Dist(p[i],p[j]);
				k++;
			}
		//initialization
		for(i=0;i<n;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
		//Minimum spaning tree
		sort(e,e+k);
		for(i=j=0;i<k;i++)
		{
			u=find_set(e[i].source);
			v=find_set(e[i].dest);
			if(u!=v)
			{
				mst[j]=e[i];
				j++;
				link(u,v);
			}
		}
		//end of mst
		sum=0;
		for(i=0;i<j;i++)
			sum+=mst[i].cost;
		printf("%.2lf\n",sum);
	}
	return 0;
}
