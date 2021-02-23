//Easy BFS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
#define inf 100000000
#define max 1005
struct Node
{
	int r,c;
}temp,u,v;
enum {WHITE=0,GREY,BLACK};
int color[max][max],d[max][max]; 
int main()
{
	int row,col,i,j,k,l,t,str,stc,endr,endc,c;
	queue<Node> q;
	while(scanf("%d%d",&row,&col)==2)
	{
		if(!row && !col)break;
		///initialization
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
			{
				color[i][j]=WHITE;
				d[i][j]=inf;
			}
		scanf("%d",&k);
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&l,&t);
			for(j=0;j<t;j++)
			{
				scanf("%d",&c);
				color[l][c]=BLACK;
			}
		}
		scanf("%d%d%d%d",&str,&stc,&endr,&endc);
		//BFS
		color[str][stc]=GREY;
		d[str][stc]=0;
		temp.r=str;
		temp.c=stc;
		q.push(temp);
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			if(u.r>0)
			{
				v.r=u.r-1;
				v.c=u.c;
				if(color[v.r][v.c]==WHITE)
				{
					color[v.r][v.c]=GREY;
					d[v.r][v.c]=d[u.r][u.c]+1;
					q.push(v);
				}
			}
			if(u.r<(row-1))
			{
				v.r=u.r+1;
				v.c=u.c;
				if(color[v.r][v.c]==WHITE)
				{
					color[v.r][v.c]=GREY;
					d[v.r][v.c]=d[u.r][u.c]+1;
					q.push(v);
				}
			}
			if(u.c>0)
			{
				v.r=u.r;
				v.c=u.c-1;
				if(color[v.r][v.c]==WHITE)
				{
					color[v.r][v.c]=GREY;
					d[v.r][v.c]=d[u.r][u.c]+1;
					q.push(v);
				}
			}
			if(u.c<(col-1))
			{
				v.r=u.r;
				v.c=u.c+1;
				if(color[v.r][v.c]==WHITE)
				{
					color[v.r][v.c]=GREY;
					d[v.r][v.c]=d[u.r][u.c]+1;
					q.push(v);
				}
			}
			color[u.r][u.c]=BLACK;
		}
		printf("%d\n",d[endr][endc]);
	}
	return 0;
}













