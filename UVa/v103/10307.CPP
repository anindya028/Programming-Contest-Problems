//BFS + MST
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;

#define Max 105
#define max 60
#define inf 1<<29

struct edge
{
	int source,dest,cost;
}e[Max*Max];
struct Node
{
	int r,c;
}temp,u,v;
enum {WHITE=0,GREY,BLACK};
int color[max][max],d[max][max],sn[max][max];
int rank[Max],parent[Max];

void link(int a,int b)
{
	if(rank[a]>rank[b])
		parent[b]=a;
	else
	{
		parent[a]=b;
		if(rank[a]==rank[b])
			rank[b]=rank[b]+1;
	}
	return;
}

int find_set(int a)
{
	if(a!=parent[a])
		parent[a]=find_set(parent[a]);
	return parent[a];
}

bool operator<(edge a,edge b)
{
	return a.cost<b.cost;
}
 
int main()
{
	int cs,t,i,j,k,row,col,a,b,n,sum;
	char s[100][100];
	queue<Node> q;
	edge mst[Max+2];
	scanf("%d\n",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d %d\n",&col,&row);
		for(i=0;i<row;i++)
			gets(s[i]);
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				sn[i][j]=-1;
		for(i=k=n=0;i<row;i++)
			for(j=0;j<col;j++)
				if(s[i][j]=='A' || s[i][j]=='S')
				{
					if(sn[i][j]==-1)
					{
						sn[i][j]=n;
						n++;
					}
					for(a=0;a<row;a++)
						for(b=0;b<col;b++)
						{
							color[a][b]=WHITE;
							if(s[a][b]=='#')color[a][b]=BLACK;
							d[a][b]=inf;
						}
					color[i][j]=GREY;
					d[i][j]=0;
					u.r=i;
					u.c=j;
					q.push(u);
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
								if(s[v.r][v.c]=='A' || s[v.r][v.c]=='S')
								{
									if(sn[v.r][v.c]==-1)
									{
										sn[v.r][v.c]=n;
										n++;
									}
									e[k].source=sn[i][j];
									e[k].dest=sn[v.r][v.c];
									e[k].cost=d[v.r][v.c];
									k++;
								}
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
								if(s[v.r][v.c]=='A' || s[v.r][v.c]=='S')
								{
									if(sn[v.r][v.c]==-1)
									{
										sn[v.r][v.c]=n;
										n++;
									}
									e[k].source=sn[i][j];
									e[k].dest=sn[v.r][v.c];
									e[k].cost=d[v.r][v.c];
									k++;
								}
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
								if(s[v.r][v.c]=='A' || s[v.r][v.c]=='S')
								{
									if(sn[v.r][v.c]==-1)
									{
										sn[v.r][v.c]=n;
										n++;
									}
									e[k].source=sn[i][j];
									e[k].dest=sn[v.r][v.c];
									e[k].cost=d[v.r][v.c];
									k++;
								}
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
								if(s[v.r][v.c]=='A' || s[v.r][v.c]=='S')
								{
									if(sn[v.r][v.c]==-1)
									{
										sn[v.r][v.c]=n;
										n++;
									}
									e[k].source=sn[i][j];
									e[k].dest=sn[v.r][v.c];
									e[k].cost=d[v.r][v.c];
									k++;
								}
								q.push(v);
							}
						}
						color[u.r][u.c]=BLACK;
					}
				}
		for(i=0;i<n;i++)
		{
			parent[i]=i;
			rank[i]=0;
		}
		sort(e,e+k);		
		for(i=j=0;i<k;i++)
		{
			a=find_set(e[i].source);
			b=find_set(e[i].dest);
			if(a!=b)
			{
				mst[j]=e[i];
				j++;
				link(a,b);
			}
		}
		for(i=sum=0;i<j;i++)
			sum+=mst[i].cost;
		printf("%d\n",sum);
	}
	return 0;
}













