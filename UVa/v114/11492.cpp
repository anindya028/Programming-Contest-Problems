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
#define inf 1<<29
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

struct node
{
	int dest,tot;
	string cost;
}x,now;

bool operator<(node a,node b)
{
	return a.tot>b.tot;
}

bool operator>(node a,node b)
{
	return a.tot<b.tot;
}

map<string,int> mp;
vector<node> adj[4005];
priority_queue<node> q;
bool visited[4005][26];
int dis[4005][26];

int main()
{
	int m,n,i,j,u,v,st,nd,lu,lv,ans;
	bool stv;
	char s1[55],s2[55],s3[55];
	string ss1,ss2,sst,sse;
	while(scanf("%d",&m)==1 && m)
	{
		scanf("%s%s",s1,s2);
		mp.clear();
		sst=s1,sse=s2;
		n=0;
		Foro(i,m)
		{
			scanf("%s%s%s",s1,s2,s3);
			ss1=s1,ss2=s2;
			if(mp.find(ss1)!=mp.end())
				u=mp[ss1];
			else
				mp[ss1]=n,u=n++,adj[u].clear();
			if(mp.find(ss2)!=mp.end())
				v=mp[ss2];
			else
				mp[ss2]=n,v=n++,adj[v].clear();
			x.dest=v;
			x.cost=s3;
			adj[u].push_back(x);
			x.dest=u;
			adj[v].push_back(x);
		}
		Foro(i,n)
			Foro(j,26)
				visited[i][j]=0,dis[i][j]=inf;
		if(mp.find(sst)==mp.end() || mp.find(sse)==mp.end())
		{
			printf("impossivel\n");
			continue;
		}
		st=mp[sst];
		nd=mp[sse];
		if(st==nd)
		{
			printf("0\n");
			continue;
		}
		x.dest=st;
		x.tot=0;
		stv=0;
		while(!q.empty())
			q.pop();
		q.push(x);
		while(!q.empty())
		{
			now=q.top();
			q.pop();
			u=now.dest;
			if(u==st)
			{
				if(stv)
					continue;
				else
					stv=1;
			}
			else
			{
				lu=now.cost[0]-'a';
				if(visited[u][lu])
					continue;
				visited[u][lu]=1;
			}
			Forc(i,adj[u])
				if(u==st)
				{
					x=adj[u][i];
					v=x.dest;
					lv=x.cost[0]-'a';
					dis[v][lv]=Min(SZ(x.cost),dis[v][lv]);
					x.tot=dis[v][lv];
					q.push(x);
				}
				else
				{
					x=adj[u][i];
					v=x.dest;
					lv=x.cost[0]-'a';
					if(lu==lv)
						continue;
					if((dis[u][lu]+x.cost.size())<dis[v][lv])
						x.tot=dis[v][lv]=dis[u][lu]+x.cost.size(),
						q.push(x);
				}
		}
		ans=inf;
		Foro(i,26)
			ans=Min(ans,dis[nd][i]);
		if(ans==inf)
			printf("impossivel\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}