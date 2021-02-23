#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))

vector< pair<int,int> > adj[10005];
int ans,vis[10005];

int dfs(int root)
{
	int fir=0,sec=0,i,j;
	vis[root]=1;
	for(i=0;i<adj[root].size();i++)
		if(!vis[adj[root][i].first])
		{
			j=adj[root][i].second+dfs(adj[root][i].first);
			if(j>fir)
				sec=fir,fir=j;
			else if(j>sec)
				sec=j;
		}
	ans=Max(ans,fir+sec);
	vis[root]=2;
	return fir;
}

int main()
{
	char s[1005];
	int i,u,v,c;
	while(gets(s))
	{
		if(!s[0])
		{
			printf("0\n");
			continue;
		}
		for(i=1;i<=10000;i++)
			adj[i].clear(),vis[i]=0;
		sscanf(s,"%d%d%d",&u,&v,&c);
		adj[u].push_back(make_pair(v,c));
		adj[v].push_back(make_pair(u,c));
		while(gets(s))
		{
			if(!s[0])
				break;
			sscanf(s,"%d%d%d",&u,&v,&c);
			adj[u].push_back(make_pair(v,c));
			adj[v].push_back(make_pair(u,c));
		}
		ans=0;
		c=dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}