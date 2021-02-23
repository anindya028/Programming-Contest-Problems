#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

queue<int> q;
int vis[30000],cost[30000];

int main()
{
	int n,m,cs=0;
	char a[1000],b[1000];
	while(scanf("%s%s",a,b)==2)
	{
		
	//	if(n>10500 || m>10500 || n<1 || m<1)
		if(strlen(a)>500 || strlen(b)>500)
			while(1);
		sscanf(a,"%d",&n);
		sscanf(b,"%d",&m);
		if(!n && !m)
			break;
		cs++;
		int now=m;
		q.push(m);
		cost[m]=0;
		vis[m]=cs;
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			
			if(now*2<=2*n && vis[now*2]!=cs)
				cost[now*2]=cost[now]+1,vis[now*2]=cs,q.push(now*2);
			if(now+1<=2*n && vis[now+1]!=cs)
				cost[now+1]=cost[now]+1,vis[now+1]=cs,q.push(now+1);
			if(now-1>0 && vis[now-1]!=cs)
				cost[now-1]=cost[now]+1,vis[now-1]=cs,q.push(now-1);
		}
		printf("%d\n",cost[n]);
	}
	return 0;
}