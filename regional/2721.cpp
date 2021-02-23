//============================================================================
// Name        : 2003A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include <iostream>

using namespace std;

int R,C;
int dr[]={1,-1,0,0,1,1,-1,-1};
int dc[]={0,0,1,-1,1,-1,1,-1};
int grid[105][105];
int point[105][105];
char board[105][105];

struct edge
{
	int u,v,c;
	edge(){}
	edge(int _u,int _v,int _c)
	{
		u = _u;
		v = _v;
		c = _c;
	}
};

vector<edge> e;

void dfs(int r,int c,int now)
{
	if(r<0 || r>=R || c<0 || c>=C || grid[r][c])
		return;
	if(board[r][c]=='.')
		return;
	grid[r][c] = now;
	int i;
	for(i=0;i<8;i++)
		dfs(r+dr[i],c+dc[i],now);
}

void convert(void)
{
	int i,j;
	for(i=0;i<R;i++)
		for(j=0;j<C;j++)
			if(grid[i][j])
				point[i][j] = point[i][j+1] = point[i+1][j] = point[i+1][j+1] = grid[i][j]; 
}

void make_edge(void)
{
	int i,j,prev;
	e.clear();
	for(i=0;i<=R;i++)
	{
		prev = -1;
		for(j=0;j<=C;j++)
		{
			if(point[i][j]!=-1)
			{
				if(prev!=-1 && point[i][j]!=point[i][prev])
					e.push_back(edge(point[i][j],point[i][prev],j-prev)),
					e.push_back(edge(point[i][prev],point[i][j],j-prev));
				prev = j;
			}
		}
	}
	
	for(j=0;j<=C;j++)
	{
		prev = -1;
		for(i=0;i<=R;i++)
		{
			if(point[i][j]!=-1)
			{
				if(prev!=-1 && point[i][j]!=point[prev][j])
					e.push_back(edge(point[i][j],point[prev][j],i-prev)),
					e.push_back(edge(point[prev][j],point[i][j],i-prev));
				prev = i;
			}
		}
	}
}

int rank[10005],parent[10005];

int find_set(int now)
{
	if(now==parent[now])
		return parent[now];
	return parent[now] = find_set(parent[now]);
}

void link(int uu,int vv)
{
	if(rank[uu]<rank[vv])
	{
		parent[uu] = vv;
	}
	else
	{
		parent[vv] = uu;
		if(rank[uu] == rank[vv])
			rank[vv]++;
	}
}

bool operator<(edge a,edge b)
{
	return a.c<b.c;
}

int main() 
{
	int i,j,cs=0;
	while(scanf("%d%d",&R,&C)==2)
	{
		if(!R && !C)
			break;
		
		for(i=0;i<R;i++)
			scanf("%s",board[i]);
		
		if(cs)
			printf("\n");
		++cs;
		printf("City %d\n",cs);
		
		memset(grid,0,sizeof(grid));
		memset(point,-1,sizeof(point));
		
		int n = 0;
		for(i=0;i<R;i++)
			for(j=0;j<C;j++)
				if(!grid[i][j] && board[i][j] == '#')
				{
					n++;
					dfs(i,j,n);
				}
		
		if(n<=1)
		{
			printf("No bridges are needed.\n");
			continue;
		}
		
		convert();
		make_edge();
		
		if(e.size()==0)
		{
			printf("No bridges are possible.\n");
			printf("%d disconnected groups\n",n);
			continue;
		}
		
		sort(e.begin(),e.end());
		for(i=1;i<=n;i++)
			rank[i] = 0,
			parent[i] = i;
		
		int cnt = 0,sum = 0; 
		for(i=0;i<e.size();i++)
		{
			int uu = find_set(e[i].u);
			int vv = find_set(e[i].v);
			if(uu != vv)
			{
				link(uu,vv);
				cnt++;
				sum+=e[i].c;
			}
		}
		
		int comp = 0;
		for(i=1;i<=n;i++)
			if(find_set(i) == i)
				comp++;
		
		
		if(cnt==1)
			printf("%d bridge of total length %d\n",cnt,sum);
		else
			printf("%d bridges of total length %d\n",cnt,sum);
			
		if(comp>1)
			printf("%d disconnected groups\n",comp);
	}
	return 0;
}