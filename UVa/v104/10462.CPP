//MST
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
#define inf 1<<29
struct edge
{
	int source,dest,cost;
	int taken;
}e[205];
int rank[105],parent[105];

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
	int cs,t,i,j,k,n,m,u,v,sum,secsum,c;
	edge mst[105],secmst[105];
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&e[i].source,&e[i].dest,&e[i].cost);
			e[i].taken=0;
		}
		if(!m)
		{
			if(n==1)printf("Case #%d : No second way\n",cs+1);
			else printf("Case #%d : No way\n",cs+1);
			continue;
		}
		for(i=1;i<=n;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
		sort(e,e+m);
		for(i=j=0;i<m;i++)
		{
			u=find_set(e[i].source);
			v=find_set(e[i].dest);
			if(u!=v)
			{
				mst[j]=e[i];
				e[i].taken=1;
				j++;
				link(u,v);
			}
		}
		if(j!=(n-1))
		{
			printf("Case #%d : No way\n",cs+1);
			continue;
		}
		if(m==1)
		{
			printf("Case #%d : No second way\n",cs+1);
			continue;
		}
		secsum=inf;
		for(i=j=0;i<m;i++)
			if(e[i].taken)
			{
				for(k=1;k<=n;k++)
				{
					rank[k]=0;
					parent[k]=k;
				}
				for(k=c=0;k<m;k++)
					if(k!=i)
					{
						u=find_set(e[k].source);
						v=find_set(e[k].dest);
						if(u!=v)
						{
							secmst[c]=e[k];
							c++;
							link(u,v);
						}
					}
				if(c==(n-1))
				{
					for(k=sum=0;k<c;k++)
						sum+=secmst[k].cost;
					if(sum<secsum)
						secsum=sum;
				}
			}
		if(secsum==inf)
			printf("Case #%d : No second way\n",cs+1);
		else 
			printf("Case #%d : %d\n",cs+1,secsum);
	}
	return 0;
}













