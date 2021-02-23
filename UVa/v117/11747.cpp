#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int parent[10005],rank[10005];

struct edge
{
	int source,dest;
	int cost;
}e[200005];

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
///sorting edges in increasing order
bool operator<(edge a,edge b)
{
	return a.cost<b.cost;
}

int main()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)==2 && n && m)
	{
		for(i=0;i<m;i++)
			scanf("%d%d%d",&e[i].source,&e[i].dest,&e[i].cost);
		for(i=0;i<n;i++)
			parent[i]=i,rank[i]=0;
		sort(e,e+m);
		vector<int> ans;
		for(i=0;i<m;i++)
		{
			int u=find_set(e[i].source);
			int v=find_set(e[i].dest);
			if(u!=v)
				link(u,v);
			else
				ans.push_back(e[i].cost);
		}
		if(!ans.size())
			printf("forest\n");
		else
		{
			printf("%d",ans[0]);
			for(i=1;i<ans.size();i++)
				printf(" %d",ans[i]);
			printf("\n");
		}
	}
	return 0;
}