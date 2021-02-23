#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

#define M 305//number of pigeon
#define N 305//number of holes
list<int> adj[M];//adjacency list of the graph
bool seen[N];//which holes are engaged
int matchL[M],matchR[N];//matchL->which pigeon is in which hole,matchR->vice versa

struct point 
{
	int x,y,po;
}p[305];

vector<point> g,h,temp;

inline int dist(point a,point b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline int triarea(point a,point b,point c)
{
	return ((a.x-b.x)*(b.y-c.y)-(a.y-b.y)*(b.x-c.x));
}

bool bpm(int u)
{
	list<int>::iterator i;
	for(i=adj[u].begin();i!=adj[u].end();i++)
	{
		if(seen[*i])continue;
		seen[*i]=true;
		
		if(matchR[*i]<0 || bpm(matchR[*i]))//this is the dfs!!!!!!
		{
			matchL[u]=*i;
			matchR[*i]=u;
			return true;
		}
	}
	return false;
}

int main()
{
	int n,i,cs=0,a,b,r,cnt,j;
	while(scanf("%d",&n)==1 && n)
	{
		g.clear(),h.clear(),temp.clear();
		Foro(i,n)
			scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].po);
		scanf("%d%d%d",&a,&b,&r);
		for(i=0;i<n;i++)
		{
			if(!p[i].po)
				continue;
			int k=triarea(p[a-1],p[b-1],p[i]);
			if(k<0)
				g.push_back(p[i]);
			else if(k>0)
				h.push_back(p[i]);
		}
		if(g.size()>h.size())
			temp=g,g=h,h=temp;
		Forc(i,g)
		{
			adj[i].clear();
			Forc(j,h)
				if(dist(g[i],h[j])<=r*r && g[i].po>h[j].po)
					adj[i].push_back(j);
		}
		cnt=0;
		Forc(j,h)
			matchR[j]=-1;
		Forc(i,g)
		{
			Forc(j,h)
				seen[j]=false;
			if(bpm(i))
				cnt++;
		}
		printf("Case %d: %d\n",++cs,cnt);
	}
	return 0;
}
