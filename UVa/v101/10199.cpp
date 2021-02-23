//UVa 10199->Articulation Point
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
#include<map>
using namespace std;	

#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1<<29
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)
//map
struct species
{
	char s[80];
}c1,c2;
bool operator==(const species &a,const species &b)
{
	return !strcmp(a.s,b.s);
}
bool operator<(const species &a,const species &b)
{
	return strcmp(a.s,b.s)<0;
}

map<species,int> mp;
map<int,species> bp;

#define SIZE 105
//data for articulation
int low[SIZE],d[SIZE],col[SIZE],t_edge[SIZE];
vector<int> adj[SIZE];
int tim,art[SIZE];

enum{WHITE=0,GREY,BLACK};

void visit(int node)
{
	int i;
	low[node]=d[node]=++tim;
	col[node]=GREY;
	Forc(i,adj[node])
	{
		if(col[adj[node][i]]==WHITE)
		{
			t_edge[node]++;
			visit(adj[node][i]);
			low[node]=Min(low[node],low[adj[node][i]]);
			if(low[adj[node][i]]>=d[node])
				art[node]=1;	
		}
		else if(d[adj[node][i]]<d[node])
			low[node]=Min(low[node],d[adj[node][i]]);
	}
	col[node]=BLACK;
	return;
}

int main()
{
	int n,i,e,cnt,cs=0;
	vector<species> ans;
	while(scanf("%d",&n)==1 && n)
	{
		if(cs)
			printf("\n");
		//initialization
		mp.clear();
		bp.clear();
		Foro(i,n)
			scanf("%s",c1.s),mp[c1]=i,bp[i]=c1,adj[i].clear(),low[i]=d[i]=col[i]=t_edge[i]=art[i]=0;
		//taking input
		scanf("%d",&e);
		Foro(i,e)
			scanf("%s%s",c1.s,c2.s),adj[mp[c1]].pb(mp[c2]),adj[mp[c2]].pb(mp[c1]);
		//DFS
		tim=0;
		Foro(i,n)
			if(col[i]==WHITE)
			{
				visit(i);
				if(t_edge[i]<=1)
					art[i]=0;
			}
		//artculation point counting
		cnt=0;
		ans.clear();
		Foro(i,n)
			if(art[i])
				cnt++,ans.pb(bp[i]);
		sort(ans.begin(),ans.end());
		printf("City map #%d: %d camera(s) found\n",++cs,cnt);
		Forc(i,ans)
			printf("%s\n",ans[i].s);
	}	
	return 0;
}
