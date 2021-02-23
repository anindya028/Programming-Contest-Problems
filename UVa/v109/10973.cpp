#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> adj[10005];
int f[10005];

int main()
{
	int n,t,m,i,j,k,cnt;
	int u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			adj[i].clear();
		for(i=1;i<=m;i++)
		{
			
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		cnt = 0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<adj[i].size();j++)
				f[ adj[i][j] ] = 1;
			
			for(j=0;j<adj[i].size();j++)
				for(k=0;k<adj[adj[i][j]].size();k++)
					cnt += f[ adj[ adj[i][j] ][k] ];
			
			for(j=0;j<adj[i].size();j++)
				f[ adj[i][j] ] = 0;
		}
		printf("%d\n",cnt/6);
	}
	return 0;
}