//============================================================================
// Name        : 3807.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>

using namespace std;

int kst[] = {3,0,3,0};
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
int n;

struct board
{
	int mov;
	char s[4][4];
	void print()
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j = 0;j<n;j++)
				printf(" %d",s[i][j]);
			printf("\n");
		}
	}
}target;

bool operator<(const board &a,const board &b)
{
	int i,j;
	char sa[100],sb[100];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			sa[i*n+j] = 'H' + a.s[i][j];
	sa[i*n] = 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			sb[i*n+j] = 'H' + b.s[i][j];
	sb[i*n] = 0;
	string ssa = sa, ssb = sb;
	return ssa<ssb;
}			

bool operator==(const board &a,const board &b)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a.s[i][j]!=b.s[i][j])
				return 0;
	return 1;
}

int wall[4][4][4];
set<board> vis;

int bfs(board source)
{
	vis.clear();
	queue<board> q;
	int i,j,k,prevr,prevc,nowr,nowc,ok;
	q.push(source);
	vis.insert(source);
	board u,v;
	
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		
		if(u == target)
			return u.mov;
		
		for(i=0;i<4;i++)
		{
			v = u;
			v.mov = u.mov + 1;
			
			ok = 1;
			if(i<2)
			{
				for(j=0;j<n && ok;j++)
				{
					for(k = kst[i]; k>=0 && k<n && ok; k-=dr[i])
					{
						if(v.s[k][j]<=0)
							continue;
						nowr = k;
						nowc = j;
						while(1)
						{
							if(wall[nowr][nowc][i])
								break;
							prevr = nowr;
							prevc = nowc;
							nowr += dr[i];
							nowc += dc[i];
							
							if(v.s[nowr][nowc]>0)
								break;
							if(v.s[nowr][nowc]<0 && v.s[nowr][nowc]+v.s[prevr][prevc]!=0)
							{
								ok = 0;
								break;
							}
							
							v.s[nowr][nowc] += v.s[prevr][prevc];
							v.s[prevr][prevc] = 0;
							if(!v.s[nowr][nowc])
								break;
						}
					}
				}
			}
			else
			{
				for(j=0;j<n && ok;j++)
				{
					for(k = kst[i]; k>=0 && k<n && ok; k-=dc[i])
					{
						if(v.s[j][k]<=0)
							continue;
						nowr = j;
						nowc = k;
						while(1)
						{
							if(wall[nowr][nowc][i])
								break;
							prevr = nowr;
							prevc = nowc;
							nowr += dr[i];
							nowc += dc[i];
							
							if(v.s[nowr][nowc]<0 && v.s[nowr][nowc]+v.s[prevr][prevc]!=0)
							{
								ok = 0;
								break;
							}
							
							if(v.s[nowr][nowc]>0)
								break;
							v.s[nowr][nowc] += v.s[prevr][prevc];
							v.s[prevr][prevc] = 0;
							if(!v.s[nowr][nowc])
								break;
						}
					}
				}
			}
			if(ok && vis.find(v)==vis.end())
			{
				vis.insert(v);
				q.push(v);
			}
		}
	}
	return -1;
}

int main() 
{
	int m,w,cs = 0,i,r,c,r1,c1;
	while(scanf("%d%d%d",&n,&m,&w)==3 && n)
	{
		board u;
		memset(u.s,0,sizeof(u.s));
		memset(wall,0,sizeof(wall));
		kst[0] = kst[2] = n-1;
		u.mov = 0;
		int imp = 0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&r,&c);
			u.s[r][c] = i+1;		
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&r,&c);
			if(u.s[r][c] && u.s[r][c]!=i+1)
				imp = 1;
			u.s[r][c] += -(i+1);		
		}
		
		for(i=0;i<w;i++)
		{
			scanf("%d%d%d%d",&r,&c,&r1,&c1);
			if(r==r1)
			{
				if(c<c1)
				{
					wall[r][c][2] = 1;
					wall[r1][c1][3] = 1;
				}
				else
				{
					wall[r][c][3] = 1;
					wall[r1][c1][2] = 1;
				}
			}
			else
			{
				if(r<r1)
				{
					wall[r][c][0] = 1;
					wall[r1][c1][1] = 1;
				}
				else
				{
					wall[r][c][1] = 1;
					wall[r1][c1][0] = 1;
				}
			}
		}
		
		for(i=0;i<n;i++)
		{
			wall[0][i][1] = 1;
			wall[n-1][i][0] = 1;
			wall[i][0][3] = 1;
			wall[i][n-1][2] = 1;
		}
		
		if(imp)
		{
			printf("Case %d: impossible\n\n",++cs);
			continue;
		}
		
		int ans = bfs(u);
		if(ans == -1)
			printf("Case %d: impossible\n\n",++cs);
		else
			printf("Case %d: %d moves\n\n",++cs,ans);
	}
	return 0;
}