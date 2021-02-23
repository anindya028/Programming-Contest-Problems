//MST
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

#define Max 505
struct point
{
	int x,y;
}p[Max];
int parent[Max],rank[Max];
struct edge
{
	int source,dest;
	double cost;
}e[Max*Max];

int Dist(point a,point b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
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
	int n,i,t,cs,j,k,u,v,ns,max;
	edge mst[Max-1];
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&ns,&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		for(i=k=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				e[k].source=i;
				e[k].dest=j;
				e[k].cost=Dist(p[i],p[j]);
				k++;
			}
		for(i=0;i<n;++i)
		{
			parent[i]=i;
			rank[i]=0;
		}
		sort(e,e+k);
		max=0;
		for(i=j=0;i<k && j<(n-ns);i++)
		{
			u=find_set(e[i].source);
			v=find_set(e[i].dest);
			if(u!=v)
			{
				mst[j]=e[i];
				if(mst[j].cost>max)
					max=mst[j].cost;
				j++;
				link(u,v);
			}
		}
		printf("%.2lf\n",sqrt(max));
	}
	return 0;
}
