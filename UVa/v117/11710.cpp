#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<queue>

using namespace std;

map <string,int> mp;

struct edge
{
	int source,dest,cost;
}e[160000];

bool operator<(edge a,edge b)
{
	return a.cost<b.cost;
}

int parent[402],rank[402];
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

int main()
{
	int n,m,i,j,u,v,c;
	char name[150],s[150];
	while(scanf("%d%d",&n,&m)==2 && n )
	{
		mp.clear();
		for(i=0;i<n;i++)
			scanf("%s",name),mp[name]=i,//adj[i].clear(),dis[i]=1<<29,visited[i]=0;
			parent[i]=i,rank[i]=0;
		for(i=j=0;i<m;i++)
		{
			scanf("%s%s%d",name,s,&c);
			u=mp[name],v=mp[s];

			e[j].source=u,e[j].dest=v,e[j].cost=c,j++;
			e[j].source=v,e[j].dest=u,e[j].cost=c,j++;
		}
		scanf("%s",name);

		sort(e,e+2*m);
		int ans=0;
		for(i=j=0;i<2*m;i++)
		{
			u=find_set(e[i].source);
			v=find_set(e[i].dest);
			if(u!=v)
				ans+=e[i].cost,
				j++,link(u,v);
		}
		

		if(j==(n-1))
			printf("%d\n",ans);
		else
			printf("Impossible\n");
	}
	return 0;
}
