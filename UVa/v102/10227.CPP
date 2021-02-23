//Disjoint Forest Union-Find
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define Max 105
struct pers
{
	int fall[Max];
	int n;
}per[Max];

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

bool same(int a,int b)
{
	int i;
	if(per[a].n!=per[b].n )
		return false;
	for(i=0;i<per[a].n;i++)
		if(per[a].fall[i] != per[b].fall[i])
			return false;
	return true;
}

int main()
{
	int t,i,p,tree,j,cs,u,v,cnt,found;
	char s[105];
	bool e[Max];
	gets(s);
	sscanf(s,"%d",&t);
	gets(s);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		gets(s);
		sscanf(s,"%d%d",&p,&tree);
		for(i=1;i<=p;i++)
		{
			parent[i]=i;
			rank[i]=0;
			per[i].n=0;
			e[i]=false;
		}
		while(gets(s) && strlen(s)>0)
		{
			sscanf(s,"%d%d",&u,&v);
			found=0;
			for(i=0;i<per[u].n;i++)
				if(per[u].fall[i]==v)
					found=1;
			if(!found)
			{
				per[u].fall[per[u].n]=v;
				per[u].n++;
			}
		}
		for(i=1;i<=p;i++)
			if(per[i].n>1)
				sort(per[i].fall,per[i].fall+per[i].n);
		for(i=1;i<=p;i++)
			for(j=i+1;j<=p;j++)
				if(same(i,j))
				{
					u=find_set(i);
					v=find_set(j);
					if(u!=v)
						link(u,v);
				}
		for(i=1;i<=p;i++)
			e[find_set(i)]=true;
		cnt=0;
		for(i=1;i<=p;i++)
			if(e[i])
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}

