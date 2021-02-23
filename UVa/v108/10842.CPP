#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define size 105

struct edge
{
	int source,dest;
	double cost;
}e[size*size];
int parent[size],rank[size];
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
	return a.cost>b.cost;
}



int main()
{
	int n,m,i,mn,k,cs,t,u,v,c,j;
	edge mst[size-1];
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		k=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			if(u==v)
				continue;
			e[k].source=u;
			e[k].dest=v;
			e[k].cost=c;
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
		mn=100000000;
		for(i=j=0;i<k;i++)
		{
			u=find_set(e[i].source);
			v=find_set(e[i].dest);
			if(u!=v)
			{
				mst[j]=e[i];
				if(e[i].cost<mn)
					mn=e[i].cost;
				j++;
				link(u,v);
			}
		}
		//end of mst
		printf("Case #%d: %d\n",cs+1,mn);
	}
	return 0;
}

