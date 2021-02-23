#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define Min(a,b) (((a)<(b))?(a):(b))

struct point
{
	int x,y;
}p[25];

vector<int> adj[20][20];

int triarea(point a,point b,point c)
{
	return ((a.x-b.x)*(b.y-c.y) - (a.y-b.y)*(b.x-c.x));
}

int dp[1<<17],n,m;

int make(int now)
{
	if(now==((1<<n)-1))
		return 0;
	int i,j,k,next,cnt=0;
	for(i=0;i<n;i++)
		if(now & 1<<i)
			cnt++;
	if(cnt>=m)
		return 0;
	if(dp[now]!=-1)
		return dp[now];
	dp[now]=1000;
	
	for(i=cnt=0;i<n;i++)
		if(!(now & 1<<i))
		{
			cnt++;
			for(j=0;j<n;j++)
				if(!(now & 1<<j))
				{
					next = now | (1<<i) | (1<<j);
					for(k=0;k<adj[i][j].size();k++)
						next|= (1<<adj[i][j][k]);
					k=make(next);
					dp[now]=Min(dp[now],1+k);
				}
		}
	if(cnt==1)
		dp[now]=1;
	return dp[now];
}

int main()
{
	int t,cs,i,j,k;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&m);
		if(cs)
			printf("\n");
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(j==i)
					continue;
				adj[i][j].clear();
				for(k=0;k<n;k++)
				{
					if(i==k || j==k)
						continue;
					if(!triarea(p[i],p[j],p[k]))
						adj[i][j].push_back(k);
				}
			}
		mem(dp,-1);
		printf("Case #%d:\n%d\n",cs+1,make(0));
	}
	return 0;
}