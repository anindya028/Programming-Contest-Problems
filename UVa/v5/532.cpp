#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
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

enum{WHITE=0,GREY,BLACK};
struct node
{
	int l,r,c;
}st,u,v,nd;

int dl[]={0,0,0,0,1,-1};
int dr[]={-1,1,0,0,0,0};
int dc[]={0,0,1,-1,0,0};
int L,R,C;
char s[35][35][35];
int col[35][35][35],d[35][35][35];
queue<node> q;

bool valid(node now)
{
	return (now.l>=0 && now.l<L && now.r>=0 && now.r<R && now.c>=0 && now.c<C);
}

int main()
{
	int i,j,k;
	while(scanf("%d%d%d",&L,&R,&C)==3 && L && R && C)
	{
		Foro(i,L)
			Foro(j,R)
				scanf("%s",s[i][j]);
		Foro(i,L)
			Foro(j,R)
				Foro(k,C)
				{
					col[i][j][k]=WHITE,d[i][j][k]=inf;
					if(s[i][j][k]=='S')
					{
						st.l=i;
						st.r=j;
						st.c=k;
					}
					else if(s[i][j][k]=='E')
					{
						nd.l=i;
						nd.r=j;
						nd.c=k;
					}
					else if(s[i][j][k]=='#')
						col[i][j][k]=BLACK;
				}
		col[st.l][st.r][st.c]=GREY;
		d[st.l][st.r][st.c]=0;
		q.push(st);
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			Foro(i,6)
			{
				v.l=u.l+dl[i];
				v.r=u.r+dr[i];
				v.c=u.c+dc[i];
				if(valid(v) && col[v.l][v.r][v.c]==WHITE)
				{
					col[v.l][v.r][v.c]=GREY;
					d[v.l][v.r][v.c]=d[u.l][u.r][u.c]+1;
					q.push(v);
				}
			}
			col[u.l][u.r][u.c]=BLACK;
		}
		if(d[nd.l][nd.r][nd.c]==inf)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",d[nd.l][nd.r][nd.c]);
	}		
	return 0;
}
