#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<set>
using namespace std;	

#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1<<29
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

//flow data
#define maxv 105 
int cap[maxv][maxv],parent[maxv];
set<int> adj[maxv];
queue<int> q;
bool visited[maxv];

//finding augmenting path using BFS
int find_path(int n,int source,int sink)
{
	int i,now,path_cap;
	set<int>::iterator it;
	Foro(i,n)
		visited[i]=0,parent[i]=-1;
	while(!q.empty())
		q.pop();
	q.push(source);
	visited[source]=1;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(it=adj[now].begin();it!=adj[now].end();it++)
			if(!visited[*it] && cap[now][*it]>0)
			{
				parent[*it]=now,visited[*it]=1,q.push(*it);
				if(*it==sink)
					goto done;
			}
	}
done:
	if(!visited[sink])
		return 0;//no path found
	path_cap=inf;
	now=sink;
	while(parent[now]>-1)
		path_cap=Min(path_cap,cap[parent[now]][now]),//capacity of path
		now=parent[now];
	now=sink;
	while(parent[now]>-1)
	{
		cap[parent[now]][now]-=path_cap;
		if(cap[parent[now]][now]==0)
			adj[parent[now]].erase(adj[parent[now]].find(now));
		if(cap[now][parent[now]]==0)
			adj[now].insert(parent[now]);
		cap[now][parent[now]]+=path_cap;
		now=parent[now];//updating the flow network
	}
	return path_cap;
}

int main()
{
	int n,m,i,j,u,v,c,mxflow;
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		Foro(i,2*n+1)
		{
			adj[i].clear();
			Foro(j,2*n+1)
				cap[i][j]=0;
		}
		cap[1][n+1]=inf,adj[1].insert(n+1);
		cap[n][n+n]=inf,adj[n].insert(n+n);
		For(i,2,n)
			scanf("%d%d",&u,&c),cap[u][u+n]=c,adj[u].insert(u+n);
		Foro(i,m)
			scanf("%d%d%d",&u,&v,&c),cap[u+n][v]=cap[v+n][u]=c,adj[u+n].insert(v),adj[v+n].insert(u);
		mxflow=0;
		while(1)
		{
			c=find_path(2*n+1,1,n+n);
			if(!c)
				break;
			mxflow+=c;
		}
		printf("%d\n",mxflow);
	}
	return 0;
}