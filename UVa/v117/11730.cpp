#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define Min(a,b) (((a)<(b))?(a):(b))

vector<int> adj[1005];

int main()
{
	int s,t,i,cs=0,j,temp;
	for(i=2;i<=1000;i++)
	{
		temp=i;
		for(j=2;j*j<=temp;j++)
			if(temp%j==0)
			{
				adj[i].push_back(j);
				while(temp%j==0)
					temp/=j;
			}
		if(temp>1 && temp!=i)
			adj[i].push_back(temp);
	}
	while(scanf("%d%d",&s,&t)==2 && s && t)
	{
		int vis[1005]={0},dis[1005];
		for(i=0;i<=1000;i++)
			dis[i]=(1<<28);
		
		queue<int> q;
		q.push(s);
		dis[s]=0;
		while(!q.empty())
		{
			j=q.front();
			q.pop();

			if(j>1000 || vis[j])
				continue;
			vis[j]=1;

			if(j==t)
				break;

			for(i=0;i<adj[j].size();i++)
				temp=j+adj[j][i],dis[temp]=Min(dis[temp],dis[j]+1),q.push(temp);
		}
		if(dis[t]==(1<<28))
			printf("Case %d: -1\n",++cs);
		else
			printf("Case %d: %d\n",++cs,dis[t]);
	}
	return 0;
}