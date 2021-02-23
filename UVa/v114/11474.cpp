#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<map>
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

struct point 
{
	int x,y;
}p;

vector<point> tr[1005];
bool visited[1005];
vector<int> adj[1005];
queue<int> q;

int dist(point a,point b)
{
	return sq(a.x-b.x)+sq(a.y-b.y);
}

int main()
{
	int n,flag,i,j,m,k,d,b,T,cs,s,u,v;
	scanf("%d",&T);
	Foro(cs,T)
	{
		scanf("%d%d%d%d",&n,&m,&k,&d);
		Foro(i,m)
			scanf("%d%d",&p.x,&p.y),tr[i].clear(),tr[i].pb(p);
		for(;i<m+n;++i)
		{
			tr[i].clear();
			scanf("%d",&b);
			Foro(j,b)
				scanf("%d%d",&p.x,&p.y),tr[i].pb(p);
		}
		Foro(i,m+n)
			adj[i].clear(),visited[i]=false;
		Foro(i,m+n)
			For(j,i+1,m+n)
			{
				Forc(u,tr[i])
					Forc(v,tr[j])
					{
						s=dist(tr[i][u],tr[j][v]);
						if(((i<m || j<m) && s<=d*d) || ((i>=m && j>=m) && s<=k*k))
						{
							adj[i].pb(j);
							adj[j].pb(i);
							goto hell;
						}
					}
				hell:;
			}
		while(!q.empty())
			q.pop();
		s=m;
		q.push(m);
		visited[m]=true;
		flag=0;
		while(!q.empty() && !flag)
		{
			u=q.front();
			q.pop();
			Forc(i,adj[u])
			{
				if(adj[u][i]<m)
					flag=1;
				v=adj[u][i];
				if(!visited[v])
					q.push(v),visited[v]=true;
			}
		}
		if(flag)
			printf("Tree can be saved :)\n");
		else
			printf("Tree can't be saved :(\n");
	}
	return 0;
}