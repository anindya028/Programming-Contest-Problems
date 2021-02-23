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

int R,C;
char s[80][80];
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
struct node
{
	int r,c;
}st,nd,u,v;
queue<node> q;
int col[80][80],d[80][80];
enum{WHITE=0,GREY,BLACK};

bool valid(node k)
{
	return (k.r>=0 && k.r<R && k.c>=0 && k.c<C);
}

int main()
{
	int w,h,i,j,cs=0,k,qu;
	char temp[78];
	while(gets(temp) && sscanf(temp,"%d%d",&w,&h)==2 && w && h)
	{
		R=h+2,C=w+2;
		Foro(i,R)
			s[i][0]=s[i][C-1]=' ';
		Foro(i,C)
			s[0][i]=s[R-1][i]=' ';
		Fore(i,1,h)
		{
			gets(temp);
			for(j=1,k=0;temp[k];j++,k++)
				s[i][j]=temp[k];
		}
		printf("Board #%d:\n",++cs);
		qu=0;
		while(gets(temp) && sscanf(temp,"%d%d%d%d",&st.c,&st.r,&nd.c,&nd.r)==4 && st.r && st.c)
		{
			s[st.r][st.c]=s[nd.r][nd.c]=' ';
			Foro(i,R)
				Foro(j,C)
					col[i][j]=WHITE,d[i][j]=inf;
			col[st.r][st.c]=GREY;
			d[st.r][st.c]=0;
			q.push(st);
			while(!q.empty())
			{
				u=q.front();
				q.pop();
				Foro(i,4)
				{
					v.r=u.r+dr[i];
					v.c=u.c+dc[i];
					while(valid(v) && s[v.r][v.c]==' ')
					{
						d[v.r][v.c]=Min(d[v.r][v.c],d[u.r][u.c]+1);
						if(col[v.r][v.c]==WHITE)
						{
							col[v.r][v.c]=GREY;
							q.push(v);
						}
						v.r=v.r+dr[i];
						v.c=v.c+dc[i];
					}
				}
				col[u.r][u.c]=BLACK;
			}
			printf("Pair %d: ",++qu);
			if(d[nd.r][nd.c]!=inf)
				printf("%d segments.\n",d[nd.r][nd.c]);
			else
				printf("impossible.\n");
			s[st.r][st.c]=s[nd.r][nd.c]='X';
		}
		printf("\n");
	}
	return 0;
}
