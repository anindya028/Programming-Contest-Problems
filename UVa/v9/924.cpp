#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
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

queue<int> q;
vector<int> adj[2505];

int main()
{
	int n,i,e,t,cs,j,s,u,v,d[2505],cnt[2505],pos,mx;
	bool visited[2505];
	while(scanf("%d",&n)==1)
	{
		Foro(i,n)
		{
			scanf("%d",&e);
			adj[i].clear();
			Foro(j,e)
				scanf("%d",&u),adj[i].pb(u);
		}
		scanf("%d",&t);
		Foro(cs,t)
		{
			scanf("%d",&s);
			Foro(i,n+2)
				visited[i]=false,d[i]=inf,cnt[i]=0;
			visited[s]=true;
			d[s]=0;
			cnt[0]++;
			mx=-1;
			q.push(s);
			while(!q.empty())
			{
				u=q.front();
				q.pop();
				Forc(i,adj[u])
					if(!visited[adj[u][i]])
					{
						v=adj[u][i];
						visited[v]=1;
						d[v]=d[u]+1;
						cnt[d[v]]++;
						if(cnt[d[v]]>mx)
						{
							mx=cnt[d[v]];
							pos=d[v];
						}
						q.push(v);
					}
			}
			if(mx==-1)
				printf("0\n");
			else
				printf("%d %d\n",mx,pos);
		}
	}
	return 0;
}
