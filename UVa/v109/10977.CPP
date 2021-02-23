//BFS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;	

#define inf 1<<29
#define Max(a,b) (((a)>(b))?(a):(b)) 
enum{White=0,Grey,Black};

int dist(int x1,int y1,int x2,int y2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int dis[205][205];
int col[205][205];
struct node
{
	int x,y;
	void ini(int x0,int y0){x=x0,y=y0;}
}temp,u,v;
queue<node> q;

int main()
{
	int r,c,m,x,y,l,n,k;
	register int i,j;
	while(scanf("%d%d",&r,&c)==2)
	{
		if(!r && !c)
			break;
		scanf("%d",&m);
		for(i=1;i<=r;++i)
			for(j=1;j<=c;++j)
				col[i][j]=White,dis[i][j]=inf;
		dis[1][1]=0;
		for(i=0;i<m;++i)
			scanf("%d%d",&x,&y),col[x][y]=Black;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d%d%d",&x,&y,&l);
			for(j=Max(x-l,1);j<=(x+l) && j<=r;++j)
				for(k=Max(y-l,1);k<=(y+l) && k<=c;++k)
					if(dist(j,k,x,y)<=l*l)
						col[j][k]=Black;
		}
		if(col[1][1]==Black)
		{
			printf("Impossible.\n");
			continue;
		}
		//BFS
		temp.x=temp.y=1;
		q.push(temp);
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			if(u.x>1)
			{
				v.ini(u.x-1,u.y);
				if(col[v.x][v.y]==White)
				{
					col[v.x][v.y]=Grey;
					dis[v.x][v.y]=dis[u.x][u.y]+1;
					q.push(v);
				}
			}
			if(u.x<r)
			{
				v.ini(u.x+1,u.y);
				if(col[v.x][v.y]==White)
				{
					col[v.x][v.y]=Grey;
					dis[v.x][v.y]=dis[u.x][u.y]+1;
					q.push(v);
				}
			}
			if(u.y>1)
			{
				v.ini(u.x,u.y-1);
				if(col[v.x][v.y]==White)
				{
					col[v.x][v.y]=Grey;
					dis[v.x][v.y]=dis[u.x][u.y]+1;
					q.push(v);
				}
			}
			if(u.y<c)
			{
				v.ini(u.x,u.y+1);
				if(col[v.x][v.y]==White)
				{
					col[v.x][v.y]=Grey;
					dis[v.x][v.y]=dis[u.x][u.y]+1;
					q.push(v);
				}
			}
			col[u.x][u.y]=Black;
		}
		if(dis[r][c]<inf)
			printf("%d\n",dis[r][c]);
		else
			printf("Impossible.\n");
	}
	return 0;
}









