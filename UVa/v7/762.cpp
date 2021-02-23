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
#define SIZE 700

enum{WHITE=0,GREY,BLACK};

struct node
{
	char s[10];
}u,v;

bool operator<(node a,node b)
{
	return strcmp(a.s,b.s)<0;
}

bool operator==(node a,node b)
{
	return !strcmp(a.s,b.s);
}

map<node,int> fmp;
map<int,node> bmp;
vector<int> adj[SIZE];
queue<int> q;
int col[SIZE],parent[SIZE];

int main()
{
	int n,m,i,a,b,now,next,trail[SIZE],k,cs=0;
	map<node,int>::iterator it;
	while(scanf("%d",&m)==1)
	{
		if(cs)
			printf("\n");
		cs++;
		fmp.clear();
		bmp.clear();
		n=0;
		Foro(i,SIZE)
			adj[i].clear();
		Foro(i,m)
		{
			scanf("%s%s",u.s,v.s);
			it=fmp.find(u);
			if(it!=fmp.end())
				a=fmp[u];
			else
				a=n,fmp[u]=n,bmp[n]=u,n++;
			it=fmp.find(v);
			if(it!=fmp.end())
				b=fmp[v];
			else
				b=n,fmp[v]=n,bmp[n]=v,n++;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		Foro(i,n)
			col[i]=WHITE,parent[i]=-1;
		scanf("%s%s",u.s,v.s);
		it=fmp.find(u);
		if(it==fmp.end())
		{
			printf("No route\n");
			continue;
		}
		it=fmp.find(v);
		if(it==fmp.end())
		{
			printf("No route\n");
			continue;
		}
		a=fmp[u];
		b=fmp[v];
		col[a]=GREY;
		parent[a]=a;
		q.push(a);
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			Forc(i,adj[now])
				if(col[adj[now][i]]==WHITE)
				{
					next=adj[now][i];
					col[next]=GREY;
					parent[next]=now;
					q.push(next);
				}
			col[now]=BLACK;
		}
		if(parent[b]==-1)
		{
			printf("No route\n");
			continue;
		}
		k=0;
		trail[k]=b;
		k++;
		now=b;
		while(parent[now]!=now)
			trail[k++]=parent[now],now=parent[now];
		for(i=k-1;i>=1;i--)
		{
			u=bmp[trail[i]];
			v=bmp[trail[i-1]];
			printf("%s %s\n",u.s,v.s);
		}
	}
	return 0;
}
