#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;

#define Min(a,b) (((a)<(b))?(a):(b))

struct node
{
	int dest,cost;
}temp,uu,vv;

bool operator<(node a,node b)
{
	return a.cost>b.cost;
}

int ish[10005],hotel[105],vis[10005];

vector<node> adj[10005];
map<int,int> mp;
priority_queue<node> pq;

vector<int> hh[105];

int dp[105],hvis[105];

int make(int now)
{
	if(now==-1 || hotel[now]==1)
		return 0;
	if(dp[now]!=-1)
		return dp[now];
	if(hvis[now])
		return 1<<20;
	dp[now]=1<<20;
	hvis[now]=1;
	int i,j;
	for(i=0;i<hh[now].size();i++)
		j=1+make(hh[now][i]),
		dp[now]=Min(dp[now],j);
	return dp[now]; 
}

int main()
{
	int n,h,m,i,j,u,v,c;
	while(scanf("%d",&n)==1 && n)
	{
		mp.clear();
		for(i=1;i<=n;i++)
			ish[i]=0,adj[i].clear();
		scanf("%d",&h);
		for(i=0;i<h;i++)
			scanf("%d",&hotel[i]),ish[hotel[i]]=1,mp[hotel[i]]=i,hh[i].clear();
		hh[h].clear();
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&c);
			if(u==v)
				continue;
			temp.dest=v,temp.cost=c;
			adj[u].push_back(temp);
			temp.dest=u;
			adj[v].push_back(temp);
		}
		
		
		hotel[h]=n;
		if(mp.find(1)==mp.end())
			mp[1]=-1;
		ish[1]=1;

		for(i=0;i<=h;i++)
		{
			memset(vis,0,sizeof(vis));
			uu.dest=hotel[i],uu.cost=0;			
			pq.push(uu);
			while(!pq.empty())
			{
				uu=pq.top();
				pq.pop();

				if(uu.cost>600)
					continue;
				u=uu.dest;
				if(vis[u])
					continue;
				if(ish[u])
					hh[i].push_back(mp[u]);
				vis[u]=1;
				for(j=0;j<adj[u].size();j++)
				{
					vv.dest=adj[u][j].dest;
					vv.cost=adj[u][j].cost+uu.cost;
					if(vv.cost<=600)
						pq.push(vv);
				}
			}
		}
		int ans=1<<20;
		memset(dp,-1,sizeof(dp));
		memset(hvis,0,sizeof(hvis));
		for(i=0;i<hh[h].size();i++)
			j=make(hh[h][i]),ans=Min(ans,j);
		if(ans==1<<20)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}