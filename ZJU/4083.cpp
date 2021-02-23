#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>

using namespace std;

#define mem(a,b) (memset(a,b,sizeof(a)))

char parent[7][7][7][7],vis[7][7][7][7];
char grid[2][7][7];
int adj[2][7][7][4];
int pa[7][7][7][7][2];

struct node
{
	int r[2],c[2];
	int dir;
	int tk[2];
}u,v,tar;

int giv[2][7][7];

int dr[]={1,0,0,-1};
int dc[]={0,-1,1,0};

bool ok(node g)
{
	bool f=1;
	int k;
	for(k=0;k<2 && f;k++)
		if(g.r[k]<0 || g.r[k]>=6 || g.c[k]<0 || g.c[k]>=6 || grid[k][g.r[k]][g.c[k]])
			f=0;
	return f;
}

char ss[]={"DLRU"};

void print(node now)
{
	if(parent[now.r[0]][now.c[0]][now.r[1]][now.c[1]]==5)
		return;
	int dd=parent[now.r[0]][now.c[0]][now.r[1]][now.c[1]],k,npa[2];
	for(k=0;k<2;k++)
		npa[k]=pa[now.r[0]][now.c[0]][now.r[1]][now.c[1]][k];
	for(k=0;k<2;k++)
		v.r[k]=now.r[k]-npa[k]*dr[dd],
		v.c[k]=now.c[k]-npa[k]*dc[dd];

	print(v);
	printf("%c",ss[dd]);
}

int main()
{
	int i,j,t,cs,k,w;
	int mp[4];
	mp[0]=1,mp[1]=0,mp[2]=2,mp[3]=3;
	scanf("%d",&t);
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			scanf("%d",&giv[0][i][j]);
	for(cs=0;cs<t-1;cs++)
	{
		for(i=0;i<6;i++)
			for(j=0;j<6;j++)
				scanf("%d",&giv[1][i][j]);

		mem(grid,0);
		mem(adj,0);
		mem(parent,-1);
		mem(vis,0);

		for(k=0;k<2;k++)
			for(i=0;i<6;i++)
				for(j=0;j<6;j++)
				{
					for(w=0;w<4;w++)
						adj[k][i][j][mp[w]]=!(giv[k][i][j] & (1<<w));
					if(!(giv[k][i][j] & (1<<4)))
						grid[k][i][j]=1;
					if(giv[k][i][j] & (1<<5))
						u.r[k]=i,u.c[k]=j;
					if(giv[k][i][j] & (1<<6))	
						tar.r[k]=i,tar.c[k]=j;
				}	
		
		u.dir=5;
		queue<node> q;
		vis[u.r[0]][u.c[0]][u.r[1]][u.c[1]]=1;
		parent[u.r[0]][u.c[0]][u.r[1]][u.c[1]]=5;
		q.push(u);
		while(!q.empty())
		{
			v=q.front();
			q.pop();

			int got=1;
			for(k=0;k<2;k++)
				if(tar.r[k]!=v.r[k] || tar.c[k]!=v.c[k])
					got=0;

			if(got)
				break;

			for(i=0;i<4;i++)
			{
				for(k=0;k<2;k++)
					u.tk[k]=adj[k][v.r[k]][v.c[k]][i],
					u.r[k]=v.r[k]+u.tk[k]*dr[i],
					u.c[k]=v.c[k]+u.tk[k]*dc[i];
				u.dir=i;
				if(!ok(u))
					continue;
				if(vis[u.r[0]][u.c[0]][u.r[1]][u.c[1]])
					continue;
				vis[u.r[0]][u.c[0]][u.r[1]][u.c[1]]=1;
				parent[u.r[0]][u.c[0]][u.r[1]][u.c[1]]=u.dir;
				for(k=0;k<2;k++)
					pa[u.r[0]][u.c[0]][u.r[1]][u.c[1]][k]=u.tk[k];
				q.push(u);
			}
		}
		if(parent[tar.r[0]][tar.c[0]][tar.r[1]][tar.c[1]]==-1)
			printf("-1\n");
		else
		{
			print(tar);
			printf("\n");
		}
		//
		for(i=0;i<6;i++)
			for(j=0;j<6;j++)
				giv[0][i][j]=giv[1][i][j];
	}
	return 0;
}