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
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

#define SIZE 105

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
	int n,i,p,q,bs,dbs,cnt;
	char s[1000];
	while(gets(s) && sscanf(s,"%d",&n)==1 && n)
	{
		//initialization
		Foro(i,n)
			adj[i].clear(),col[i]=WHITE,art[i]=low[i]=d[i]=t_edge[i]=0;
		//taking input
		while(gets(s))
		{
			bs=0;
			sscanf(s+bs,"%d%n",&p,&dbs);
			if(!p)
				break;
			bs+=dbs;
			while(sscanf(s+bs,"%d%n",&q,&dbs)==1)
				adj[p-1].pb(q-1),adj[q-1].pb(p-1),bs+=dbs;
		}
		//DFS
		tim=0;
		Foro(i,n)
			if(col[i]==WHITE)
			{
				visit(i);
				if(t_edge[i]<=1)
					art[i]=0;
			}
		//articulation point
		cnt=0;
		Foro(i,n)
			if(art[i])
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
