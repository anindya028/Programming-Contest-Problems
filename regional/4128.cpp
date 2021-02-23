#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

#define inf 1000000000

vector< pair<int,int> > cost[105][105];
int R,C;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

struct node
{
	int r,c,dir,vv;
	int sum,last;
};

bool operator<(node a,node b)
{
	return a.sum>b.sum;
}

bool operator==(node a,node b)
{
	return (a.r==b.r && a.c==b.c);
}

char vis[105][105][5][2];
int dis[105][105][5][2];

int main()
{
	node st,nd;
	int i,j,k,cs=0,v;
	while(scanf("%d%d%d%d%d%d",&R,&C,&st.r,&st.c,&nd.r,&nd.c)==6)
	{
		if(!R)
			break;
		cs++;
		for(i=1;i<=R;i++)
			for(j=1;j<=C;j++)
			{
				cost[i][j].clear();
				for(k=0;k<5;k++)
					dis[i][j][k][0]=dis[i][j][k][1]=inf;
			}

		for(i=1;i<2*R;i++)
		{
			if(i%2)
				for(j=1;j<C;j++)
				{
					scanf("%d",&v);
					if(!v)
						continue;
					cost[(i+1)/2][j].push_back(make_pair(2,v));
					cost[(i+1)/2][j+1].push_back(make_pair(3,v));
				}
			else
				for(j=1;j<=C;j++)
				{
					scanf("%d",&v);
					if(!v)
						continue;
					cost[i/2][j].push_back(make_pair(0,v));
					cost[i/2 + 1][j].push_back(make_pair(1,v));
				}
		}
		
		int got=0;
		st.vv = 0;
		st.sum = 0;
		st.last = 0;
		st.dir = 4;
		
		memset(vis,0,sizeof(vis));
		
		priority_queue<node> q;
		vis[st.r][st.c][st.dir][st.last]=0;
		dis[st.r][st.c][st.dir][st.last]=0;
		q.push(st);
		
		int ans = inf;

		while(!q.empty())
		{
			node u = q.top();
			q.pop();

			if(u==nd)
			{
				int v = u.sum + u.last*u.vv;
				if(v<ans)
					ans=v;
			}
			
			if(vis[u.r][u.c][u.dir][u.last])
				continue;
			vis[u.r][u.c][u.dir][u.last] = 1;

			vector< pair<int,int> > now = cost[u.r][u.c];

			for(i=0;i<now.size();i++)
			{
				node next;
				next.r = u.r + dr[now[i].first];
				next.c = u.c + dc[now[i].first];
				next.dir = now[i].first;
				
				if(now[i].first!=u.dir)
					v = 2*now[i].second + u.last*u.vv,
					next.last = 0;
				else
					v = now[i].second,
					next.last = 1;
				
				next.vv = now[i].second;
				next.sum = u.sum + v;

				if(next.sum<dis[next.r][next.c][next.dir][next.last])
				{
					q.push(next);
					dis[next.r][next.c][next.dir][next.last] = next.sum;
				}
			}
		}
		
		if(ans == inf)
			printf("Case %d: Impossible\n",cs);
		else
			printf("Case %d: %d\n",cs,ans);
	}
	return 0;
}