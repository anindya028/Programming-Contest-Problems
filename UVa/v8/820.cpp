#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
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
queue<int> q;
bool visited[maxv];

//finding augmenting path using BFS
int find_path(int n,int source,int sink)
{
	int i,now,path_cap;
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
		Foro(i,n)
			if(!visited[i] && cap[now][i]>0)
			{
				parent[i]=now,visited[i]=1,q.push(i);
				if(i==sink)
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
		cap[parent[now]][now]-=path_cap,
		cap[now][parent[now]]+=path_cap,
		now=parent[now];//updating the flow network
	return path_cap;
}

int main()
{
	int n,m,s,t,i,j,u,v,c,maxflow,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		Foro(i,n+1)
			Foro(j,n+1)
				cap[i][j]=0;
		scanf("%d%d%d",&s,&t,&m);
		Foro(i,m)
			scanf("%d%d%d",&u,&v,&c),cap[u][v]+=c,cap[v][u]+=c;
		maxflow=0;
		while(1)
		{
			c=find_path(n+1,s,t);
			if(!c)
				break;
			maxflow+=c;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",++cs,maxflow);
	}
	return 0;
}
