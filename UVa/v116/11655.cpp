#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 100000

vector<int> adj[2][5005];

queue< int > q;
LL ways[2][5005];

int n;

LL make(int f,int now)
{
	if(!f)
	{
		if(now==n)
			return ways[f][now];
	}
	if(f)
	{
		if(now==1)
			return ways[f][now];
	}
	if(ways[f][now]!=-1)
		return ways[f][now];
	ways[f][now]=0;
	int i;
	for(i=0;i<adj[f][now].size();i++)
		ways[f][now]=(ways[f][now]+make(f,adj[f][now][i]))%mod;
	return ways[f][now];
}

int main()
{
	int t,cs,i,u,v,m,ans;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&m);
		while(!q.empty())
			q.pop();
		mem(ways,-1);

		for(i=1;i<=n;i++)
			adj[1][i].clear(),adj[0][i].clear();	
			
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			adj[0][u].push_back(v);
			adj[1][v].push_back(u);
		}

		ways[0][n]=1;
		ways[1][1]=1;
		ans=make(0,1);
		ans=make(1,n);
		ans=0;
		for(i=1;i<=n-1;i++)
			if(ways[0][i]>=0 && ways[1][i]>=0)
			ans=(ans + (ways[0][i]*ways[1][i])%mod )%mod;

		printf("Case %d: %d %lld\n",cs+1,ans,ways[0][1]);
	}
	return 0;
}