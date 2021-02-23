#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define Max 50005
int parent[Max],rank[Max];
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
	int i,j,k,n,m,u,v,cs=0,cnt;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m)
			break;
	
		for(i=1;i<=n;i++)
		{
			rank[i]=0;
			parent[i]=i;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&j,&k);
			u=find_set(j);
			v=find_set(k);
			if(u!=v)
				link(u,v);
		}
		cnt=0;
		for(i=1;i<=n;i++)
			if(parent[i]==i)
				cnt++;
		printf("Case %d: %d\n",++cs,cnt);
	}

	return 0;
}

