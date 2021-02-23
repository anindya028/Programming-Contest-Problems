#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>
#include <ctime>

using namespace std;

#define sz 205
vector<int> adj[sz],adjT[sz];
int visited[sz];
vector<int> order;

void dfs(int now)
{
	if(visited[now])
		return;
	visited[now] = 1;
	int i;
	for(i=0;i<adj[now].size();i++)
		dfs(adj[now][i]);
}

void dfs1(int now)
{
	if(visited[now])
		return;
	visited[now] = 1;
	int i;
	for(i=0;i<adj[now].size();i++)
		dfs1(adj[now][i]);
	order.push_back(now);
}

void dfs2(int now,int x)
{
	if(visited[now])
		return;
	visited[now] = x;
	int i;
	for(i=0;i<adjT[now].size();i++)
		dfs2(adjT[now][i],x);
}

int main()
{
	int i,j,n,m,b[5],bb[5],cs = 0,l,k;
	char vb[5][10];
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		for(i=0;i<2*n;i++)
		{
			adj[i].clear();
			adjT[i].clear();
		}

		for(i=0;i<m;i++)
		{
			scanf("%d",&k);
			for(j=0;j<k;j++)
			{
				scanf("%d%s",&b[j],vb[j]);
				b[j]--;
				bb[j] = b[j]*2 + (vb[j][0]=='y');
			}
			if(k<=2)
			{
				for(j=0;j<k;j++)
					adj[bb[j] ^ 1].push_back(bb[j]);
			}
			else
			{
				for(j=0;j<k;j++)
					for(l=0;l<k;l++)
						if(j!=l)
							adj[ bb[j] ^ 1].push_back(bb[l]);
			}
		}

		for(i=0;i<2*n;i++)
			for(j=0;j<adj[i].size();j++)
				adjT[ adj[i][j] ].push_back(i);

		memset(visited,0,sizeof(visited));
		order.clear();
		for(i=0;i<2*n;i++)
			if(!visited[i])
				dfs1(i);
		
		j = 1;
		memset(visited,0,sizeof(visited));
		for(i=order.size()-1;i>=0;i--)
		{
			if(visited[order[i]])
				continue;
			dfs2(order[i],j);
			j++;
		}

		int ok = 1;
		for(i=0;i<n;i++)
			if(visited[2*i] == visited[2*i+1])
				ok = 0;

		printf("Case %d: ",++cs);
		if(!ok)
		{
			printf("impossible\n");
			continue;
		}

		for(i=0;i<n;i++)
		{
			memset(visited,0,sizeof(visited));
			dfs(2*i);
			if(visited[2*i+1])
			{
				printf("y");
				continue;
			}
			memset(visited,0,sizeof(visited));
			dfs(2*i+1);
			if(visited[2*i])	
				printf("n");
			else
				printf("?");
		}
		printf("\n");
	}
	return 0;
}