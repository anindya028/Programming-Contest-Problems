#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;	

#define size 1005
list<int> adj[size];

int main()
{
	int n,t,cs,i,j,m,dis[1005],k;
	bool visited[1005];
	list<int>::iterator iter;
	queue<int> q;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			visited[i]=0;
			adj[i].clear();
			dis[i]=100000;
		}
		dis[0]=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&j,&k);
			adj[j].push_back(k);
			adj[k].push_back(j);
		}
		q.push(0);
		visited[0]=1;
		while(!q.empty())
		{
			k=q.front();
			q.pop();
			for(iter=adj[k].begin();iter!=adj[k].end();iter++)
				if(!visited[*iter])
				{
					dis[*iter]=dis[k]+1;
					visited[*iter]=1;
					q.push(*iter);
				}
		}
		for(i=1;i<n;i++)
			printf("%d\n",dis[i]);
	}
	return 0;
}
