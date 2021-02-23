#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define Max 1005
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
	char s[100],g[10];
	int i,n,u,v,j,k,cs,t,tr,fa;
	gets(s);
	sscanf(s,"%d",&t);
	gets(s);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		gets(s);
		sscanf(s,"%d",&n);
		for(i=1;i<=n;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
		tr=fa=0;
		while(gets(s) && strlen(s)>0)
		{
			sscanf(s,"%s%d%d",g,&j,&k);
			u=find_set(j);
			v=find_set(k);
			if(g[0]=='c')
			{
				if(u!=v)
					link(u,v);
			}
			else
			{
				if(u!=v)fa++;
				else tr++;
			}
		}
		printf("%d,%d\n",tr,fa);
	}

	return 0;
}

