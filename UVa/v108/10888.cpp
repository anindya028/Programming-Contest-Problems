#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1<<29
#define Min(a,b) (((a)<(b))?(a):(b))

char s[45][45];
struct node
{
	int r,c,dis;
}box[20],pos[20];

int n,mat[20][20],h,w;

int bfs(node source,node dest)
{
	queue<node> q;
	int visited[45][45]={0};
	int dr[]={1,-1,0,0};
	int dc[]={0,0,1,-1};
	int i;
	node u,v;
	u.r=source.r,u.c=source.c,u.dis=0;
	q.push(u);
	while(!q.empty())
	{
		v=q.front();
		q.pop();
		if(v.r==dest.r && v.c==dest.c)
			return v.dis;
		if(visited[v.r][v.c])
			continue;
		visited[v.r][v.c]=1;
		for(i=0;i<4;i++)
		{
			u.r=v.r+dr[i];
			u.c=v.c+dc[i];
			if(u.c>=0 && u.c<w && u.r>=0 && u.r<h)
				if(s[u.r][u.c]!='#')
					u.dis=v.dis+1,q.push(u);
		}
	}
	return inf;
}

int dp[1<<17];

int make(int now,int cnt)
{
	if(now==((1<<n)-1))
		return 0;
	if(dp[now]!=-1)
		return dp[now];
	dp[now]=inf;
	
	int i,j;
	for(i=0;i<n;i++)
		if(!(now & 1<<i))
			j=mat[cnt][i]+make(now | 1<<i,cnt+1),
			dp[now]=Min(dp[now],j);

	return dp[now];
}

int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&w);
		for(i=0;i<h;i++)
			scanf("%s",s[i]);
		
		for(i=n=0;i<h;i++)
			for(j=0;s[i][j];j++)
				if(s[i][j]=='B')
					box[n].r=i,box[n].c=j,n++;
		
		for(i=n=0;i<h;i++)
			for(j=0;s[i][j];j++)
				if(s[i][j]=='X')
					pos[n].r=i,pos[n].c=j,n++;
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=bfs(box[i],pos[j]);
		
		mem(dp,-1);
		printf("%d\n",make(0,0));		
	}
	return 0;
}

