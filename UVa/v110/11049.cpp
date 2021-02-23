#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
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
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)


struct node
{
	int r,c;
}s,d,u,v;

struct wall
{
	node st,nd;
}w[3];

bool check(wall wl,node a,node b,int dir)
{
	if(wl.st.r==wl.nd.r)
		if(a.c==b.c)
			if((a.r==wl.st.r && dir==0) || (b.r==wl.st.r && dir==1))
				if(wl.st.c<a.c && wl.nd.c>=b.c)
					return true;
	if(wl.st.c==wl.nd.c)
		if(a.r==b.r)
			if((a.c==wl.st.c && dir==2) || (b.c==wl.st.c && dir==3))
				if(wl.st.r<a.r && wl.nd.r>=b.r)
					return true;
	return false;
}

int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int parent[9][9];
bool visited[8][8];
queue<node> q;

int valid(node a)
{
	if(a.r && a.c && a.r<7 && a.c<7)
		return true;
	return false;
}

void path_print(node now)
{
	if(parent[now.r][now.c]==-1)
		return;
	int dir=parent[now.r][now.c];
	u.r=now.r-dr[dir];
	u.c=now.c-dc[dir];
	path_print(u);
	if(dir==0)
		printf("S");
	else if(dir==1)
		printf("N");
	else if(dir==2)
		printf("E");
	else
		printf("W");
}

int main()
{
	int i,j;
	while(scanf("%d%d",&s.c,&s.r)==2 && s.r && s.c)
	{
		scanf("%d%d",&d.c,&d.r);
		Foro(i,3)
			scanf("%d%d%d%d",&w[i].st.c,&w[i].st.r,&w[i].nd.c,&w[i].nd.r);
		Foro(i,7)
			Foro(j,7)
				parent[i][j]=-1,visited[i][j]=false;
		q.push(s);
		visited[s.r][s.c]=true;
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			Foro(i,4)
			{
				v.r=u.r+dr[i];
				v.c=u.c+dc[i];
				if(valid(v) && !check(w[0],u,v,i) && !check(w[1],u,v,i) && !check(w[2],u,v,i))
					if(!visited[v.r][v.c])
						q.push(v),parent[v.r][v.c]=i,visited[v.r][v.c]=true;
			}
		}
		path_print(d);
		printf("\n");
	}
	return 0;
}