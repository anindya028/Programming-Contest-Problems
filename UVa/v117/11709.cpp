#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

map<string,int> mp;

struct node
{
	int d,f;
	int idx;
}v[1005];

vector<int> adj[1005],adjt[1005];
int vis[1005],tim;

void dfs(int now)
{
	v[now].d=++tim;
	int i;
	vis[now]=1;
	for(i=0;i<adj[now].size();i++)
		if(!vis[adj[now][i]])
			dfs(adj[now][i]);
	v[now].f=++tim;
}

bool comp(node a,node b)
{
	return a.f>b.f;
}

void dfs1(int now)
{
	int i;
	vis[now]=1;
	for(i=0;i<adjt[now].size();i++)
		if(!vis[adjt[now][i]])
			dfs1(adjt[now][i]);
}

int main()
{
	int n,m,i,u,w;
	char s1[50],s2[50];
	string s,ss;
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		mp.clear();
		for(i=0;i<n;i++)
		{
			scanf("%s%s",s1,s2);
			s=s1,ss=s2;
			s+=ss;
			mp[s]=i;
			adj[i].clear();
			v[i].idx=i;
			adjt[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%s%s",s1,s2);
			s=s1,ss=s2;
			s+=ss;
			u=mp[s];
			scanf("%s%s",s1,s2);
			s=s1,ss=s2;
			s+=ss;
			w=mp[s];
			adj[u].push_back(w);
			adjt[w].push_back(u);
		}

		memset(vis,0,sizeof(vis));				
		tim=0;
		for(i=0;i<n;i++)
			if(!vis[i])
				dfs(i);

		memset(vis,0,sizeof(vis));
		int cnt=0;
		sort(v,v+n,comp);

		for(i=0;i<n;i++)
			if(!vis[v[i].idx])
				dfs1(v[i].idx),cnt++;

		printf("%d\n",cnt);		
	}
	return 0;
}