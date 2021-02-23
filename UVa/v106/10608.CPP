#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define Max 30005
int parent[Max],rank[Max],freq[Max];
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
	int i,j,k,n,m,u,v,cs,t,mx;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			freq[i]=rank[i]=0;
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
		for(i=1;i<=n;i++)
			freq[find_set(i)]++;
		mx=0;
		for(i=1;i<=n;i++)
			if(freq[i]>mx)
				mx=freq[i];
		printf("%d\n",mx);
	}
	return 0;
}

