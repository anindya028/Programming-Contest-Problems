//Very Good Dijkstra,Tricky
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

#define maxv 505
#define inf 1<<29
#define _min(a,b) (((a)<(b))?(a):(b))

struct node
{
	int dest,cost;
}x;
list<node> adj[maxv];

struct edge
{
	int source,dest,cost;
}ed[1005];


int main()
{
	int n,s,e,m,k,u,v,c,mn,pos,tks,tkd,res,j,cs=0;
	register int i;
	int ds[maxv],de[maxv],ps[maxv],pe[maxv],cur[maxv],temp[maxv];
	bool visited[maxv],flag;
	list<node>::iterator iter;
	while(scanf("%d%d%d",&n,&s,&e)==3)
	{
		if(cs)
			printf("\n");
		for(i=1;i<=n;i++)
		{
			adj[i].clear();
			visited[i]=false;
			ds[i]=de[i]=inf;
			ps[i]=pe[i]=i;
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			x.dest=v;
			x.cost=c;
			adj[u].push_back(x);
			x.dest=u;
			adj[v].push_back(x);
		}
		scanf("%d",&k);
		for(i=0;i<k;i++)
			scanf("%d%d%d",&ed[i].source,&ed[i].dest,&ed[i].cost);
		if(s==e)
		{
			printf("%d\n",s);
			printf("Ticket Not Used\n0\n");
			++cs;
			continue;
		}
		//dijkstra from source
		ds[s]=0;
		while(true)
		{
			mn=inf;
			for(i=1;i<=n;i++)
				if(!visited[i])
					if(ds[i]<mn)
					{
						mn=ds[i];
						pos=i;
					}
			if(mn==inf)break;
			visited[pos]=true;
			for(iter=adj[pos].begin();iter!=adj[pos].end();iter++)
				if(ds[pos]+iter->cost<ds[iter->dest])
				{
					ds[iter->dest]=ds[pos]+iter->cost;
					ps[iter->dest]=pos;
				}
		}
		//dijkstra from dest
		de[e]=0;
		for(i=1;i<=n;i++)
			visited[i]=false;
		while(true)
		{
			mn=inf;
			for(i=1;i<=n;i++)
				if(!visited[i])
					if(de[i]<mn)
					{
						mn=de[i];
						pos=i;
					}
			if(mn==inf)break;
			visited[pos]=true;
			for(iter=adj[pos].begin();iter!=adj[pos].end();iter++)
				if(de[pos]+iter->cost<de[iter->dest])
				{
					de[iter->dest]=de[pos]+iter->cost;
					pe[iter->dest]=pos;
				}
		}

		res=ds[e];
		flag=false;
		for(i=0;i<k;i++)
			if( (ds[ed[i].source] + ed[i].cost + de[ed[i].dest])<res)
			{
				res=ds[ed[i].source] + ed[i].cost + de[ed[i].dest];
				tks=ed[i].source;
				tkd=ed[i].dest;
				flag=true;
			}
			else if( ds[ed[i].dest] + ed[i].cost + de[ed[i].source] < res)
			{
				res=ds[ed[i].dest] + ed[i].cost + de[ed[i].source];
				tkd=ed[i].source;
				tks=ed[i].dest;
				flag=true;
			}
		k=0;
		if(flag)
		{
			j=0;
			temp[j]=tkd;
			j++;
			while(pe[temp[j-1]]!=e)
			{
				temp[j]=pe[temp[j-1]];
				j++;
			}
			if(e!=tkd)
			{
				temp[j]=e;
				j++;
			}
			for(i=j-1;i>=0;i--,k++)
				cur[k]=temp[i];
			
			cur[k]=tks;
			k++;
			while(ps[cur[k-1]]!=s)
			{
				cur[k]=ps[cur[k-1]];
				k++;
			}
			if(s!=tks)
			{
				cur[k]=s;
				k++;
			}
		}
		else
		{
			cur[k]=e;
			k++;
			while(ps[cur[k-1]]!=s)
			{
				cur[k]=ps[cur[k-1]];
				k++;
			}
			cur[k]=s;
			k++;
		}
		printf("%d",cur[k-1]);
		k--;
		for(i=k-1;i>=0;i--)
			printf(" %d",cur[i]);
		printf("\n");
		if(flag)
			printf("%d\n",tks);
		else
			printf("Ticket Not Used\n");
		printf("%d\n",res);
		++cs;
	}
	return 0;
}
