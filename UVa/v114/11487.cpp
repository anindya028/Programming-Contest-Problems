#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define mod 20437
#define inf 1<<29
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

char s[15][15];
int dis[15][15],ways[15][15],resd,resw,n;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
struct node
{
	int r,c;
}food[30];
bool visited[15][15];

bool isvalid(node now)
{
	if(now.r>=0 && now.r<n && now.c>=0 && now.c<n && s[now.r][now.c]=='.')
		return true;
	return false;
}

void bfs(node source,node dest)
{
	queue<node> q;
	node now,next;
	int i,j;
	Foro(i,n)
		Foro(j,n)
			dis[i][j]=inf,visited[i][j]=0;
	dis[source.r][source.c]=0;
	ways[source.r][source.c]=1;
	s[dest.r][dest.c]='.';
	q.push(source);
	visited[source.r][source.c]=1;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(now.r==dest.r && now.c==dest.c)
			break;
		for(i=0;i<4;i++)
		{
			next.r=now.r+dr[i];
			next.c=now.c+dc[i];
			if(isvalid(next))
			{
				if(!visited[next.r][next.c])
					dis[next.r][next.c]=dis[now.r][now.c]+1,
					ways[next.r][next.c]=ways[now.r][now.c],
					visited[next.r][next.c]=1,
					q.push(next);
				else if(dis[next.r][next.c]==(dis[now.r][now.c]+1))
					ways[next.r][next.c]=(ways[next.r][next.c]+ways[now.r][now.c])%mod;
			}
		}
	}
	if(dis[dest.r][dest.c]==inf)
	{
		resd=-1;
		return;
	}
	resd+=dis[dest.r][dest.c];
	resw=(resw*ways[dest.r][dest.c])%mod;
}

int main()
{
	int cnt,i,j,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		Foro(i,n)
			scanf("%s",s[i]);
		cnt=0;
		Foro(i,n)
			Foro(j,n)
				if(s[i][j]>='A' && s[i][j]<='Z')
				{
					cnt++;
					food[s[i][j]-'A'].r=i;
					food[s[i][j]-'A'].c=j;
				}
		if(cnt==1)
		{
			printf("Case %d: 0 1\n",++cs);
			continue;
		}
		s[food[0].r][food[0].c]='.';
		resw=1;
		resd=0;
		For(i,1,cnt)
		{
			bfs(food[i-1],food[i]);
			if(resd==-1)
				break;
		}
		if(resd==-1)
			printf("Case %d: Impossible\n",++cs);
		else
			printf("Case %d: %d %d\n",++cs,resd,resw);
	}
	return 0;
}