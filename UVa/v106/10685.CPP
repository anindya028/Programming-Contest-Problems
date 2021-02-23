//MAP + disjoint forest union find
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
using namespace std;

#define Max 5005
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

struct species
{
	char s[80];
}a,b;

bool operator==(const species &a,const species &b)
{
	return !strcmp(a.s,b.s);
}

bool operator<(const species &a,const species &b)
{
	return strcmp(a.s,b.s)<0;
}

map<species,int> mp;

int main()
{
	int n,m,i,j,k,u,v,mx,freq[Max];
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m)
			break;
		mp.clear();
		for(i=1;i<=n;i++)
		{
			parent[i]=i;
			rank[i]=0;
			freq[i]=0;
		}

		for(i=1;i<=n;i++)
		{
			scanf("%s",a.s);
			mp[a]=i;
		}
		
		for(i=0;i<m;i++)
		{
			scanf("%s%s",a.s,b.s);
			j=mp[a];
			k=mp[b];
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

