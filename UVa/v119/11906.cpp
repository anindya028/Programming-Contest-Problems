#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>

using namespace std;

#define inf (1<<29)
#define mem(a,b) memset(a,(b),sizeof(a))
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b)  ((a) < (b) ? (a) : (b))
typedef pair<int,int> pii;

#define ok(a) (a.first>=0 && a.first<r && a.second>=0 && a.second<c && grid[a.first][a.second]=='.')

char vis[105][105],grid[105][105];

int main()
{
	int t,cs,i,j,r,c,m,n,w,k;
	scanf("%d",&t);
	for(cs=1;cs<=t;cs++)
	{
		scanf("%d%d%d%d",&r,&c,&m,&n);
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				grid[i][j]='.';

		scanf("%d",&w);
		for(i=0;i<w;i++)
		{
			scanf("%d%d",&j,&k);
			grid[j][k]='#';
		}
	
		int dr[]={m,-m,n,-n,m,-m,n,-n};
		int dc[]={n,n,m,m,-n,-n,-m,-m};
		mem(vis,0);
		queue<pii> q;
		q.push(make_pair(0,0));
		pii u,v;
		while(!q.empty())
		{
			u=q.front();
			q.pop();

			if(vis[u.first][u.second])
				continue;
			vis[u.first][u.second]=1;

			for(i=0;i<8;i++)
			{
				v.first=u.first+dr[i];
				v.second=u.second+dc[i];
				if(ok(v))
					q.push(v);
			}
		}

		int even=0,odd=0;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				if(vis[i][j])
				{
					set<pii> nows;
					u=make_pair(i,j);
					for(k=0;k<8;k++)
					{
						v.first=u.first+dr[k];
						v.second=u.second+dc[k];

						if(ok(v) && vis[v.first][v.second])
							nows.insert(v);
					}
					int cnt=nows.size();
					if(cnt%2)
						odd++;
					else
						even++;
				}
		printf("Case %d: %d %d\n",cs,even,odd);
	}
	return 0;
}