#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

queue<int> q;

int main()
{
	int dis[10005],vis[10005],i,l,u,m,edge[15],cs=0,now;
	while(scanf("%d%d%d",&l,&u,&m)==3 && m)
	{
		if(l==u)
		{
			printf("Case %d: 0\n",++cs);
			continue;
		}
		for(i=0;i<m;i++)
			scanf("%d",&edge[i]);
		for(i=0;i<10000;i++)
			vis[i]=0,dis[i]=-1;
		vis[l]=1;
		dis[l]=0;
		q.push(l);
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			for(i=0;i<m;i++)
				if(!vis[(now+edge[i])%10000])
				{
					dis[(now+edge[i])%10000]=dis[now]+1,q.push((now+edge[i])%10000);
					vis[(now+edge[i])%10000]=1;
				}
		}
		if(dis[u]<0)
			printf("Case %d: Permanently Locked\n",++cs);
		else
			printf("Case %d: %d\n",++cs,dis[u]);
	}
	return 0;
}
