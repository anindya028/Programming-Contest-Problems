#include<stdio.h>
#include<vector>
using namespace std;

#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

vector<int> adj[10005];
bool visited[10005];

void dfs(int root)
{
	int i;
	if(visited[root])
		return;
	visited[root]=true;
	Forc(i,adj[root])
		dfs(adj[root][i]);
}

int main()
{
	int n,m,l,i,t,u,v,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&l);
		Foro(i,n)
			adj[i].clear(),visited[i]=false;
		Foro(i,m)
			scanf("%d%d",&u,&v),adj[u-1].push_back(v-1);
		Foro(i,l)
			scanf("%d",&u),dfs(u-1);
		cnt=0;
		Foro(i,n)
			if(visited[i])
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
