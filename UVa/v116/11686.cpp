#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

enum{WHITE=0,GREY,BLACK};
#define SIZE 1000005

struct node
{
	int f,no;
	char col;
}ver[SIZE];

int tim,iscyc,tot;

vector<int> adj[SIZE];
bool is[SIZE];

void dfs(int now)
{
	int i;
	//if(adj[now].size())
	ver[now].col=GREY;
	++tim;
	tot++;
	for(i=0;i<adj[now].size();i++)
		if(ver[adj[now][i]].col==GREY)
			iscyc=1;
		else if(ver[adj[now][i]].col==WHITE)
			dfs(adj[now][i]);
	ver[now].f=++tim;
	ver[now].col=BLACK;
}

bool operator<(node a,node b)
{
	return a.f>b.f;
}

int main()
{
	int n,m,i,u,v;
	while(scanf("%d%d",&n,&m)==2 && n && m)
	{
		for(i=1;i<=n;i++)
			ver[i].no=i,adj[i].clear(),is[i]=1,ver[i].col=ver[i].f=0;
		for(i=0;i<m;i++)
			scanf("%d%d",&u,&v),
			adj[u].push_back(v),is[v]=0;
		tot=tim=0;
		iscyc=0;
		for(i=1;i<=n;i++)
			if(is[i])
				dfs(i);
		if(iscyc || tot!=n)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		sort(ver+1,ver+n+1);
		for(i=1;i<=n;i++)
			printf("%d\n",ver[i].no);
	}
	return 0;
}