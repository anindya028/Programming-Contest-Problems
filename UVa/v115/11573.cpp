#include<stdio.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)
#define pb(a) push_back(a)
#define inf 1000000000

char s[1005][1005];
int dis[1005][1005];
bool vis[1005][1005];

struct he
{
	int rr,cc;
};

he calc(int p)
{
	he ret;
	if(p==0)
		ret.rr=-1,ret.cc=0;
	else if(p==1)
		ret.rr=-1,ret.cc=1;
	else if(p==2)
		ret.rr=0,ret.cc=1;
	else if(p==3)
		ret.rr=1,ret.cc=1;
	else if(p==4)
		ret.rr=1,ret.cc=0;
	else if(p==5)
		ret.rr=1,ret.cc=-1;
	else if(p==6)
		ret.rr=0,ret.cc=-1;
	else if(p==7)
		ret.rr=-1,ret.cc=-1;
	return ret;
}

struct node
{
	int row,col,cost;
}u,v;

deque<node> dq;

int main()
{
	int r,c,i,j,n,sr,sc,dr,dc;
	while(scanf("%d%d",&r,&c)==2)
	{
		Foro(i,r)
			scanf("%s",s[i]);
		scanf("%d",&n);
		while(n--)
		{
			Foro(i,r)
				Foro(j,c)
					dis[i][j]=inf,vis[i][j]=0;
			scanf("%d%d%d%d",&sr,&sc,&dr,&dc);
			sr--,sc--,dr--,dc--;
			dis[sr][sc]=0;
			while(!dq.empty())
				dq.pop_front();
			u.row=sr;
			u.col=sc;
			u.cost=0;
			dq.push_front(u);
			while(!dq.empty())
			{
				u=dq.front();
				dq.pop_front();

				if(vis[u.row][u.col])
					continue;
				vis[u.row][u.col]=1;

				if(u.row==dr && u.col==dc)
					break;

				he temp=calc(s[u.row][u.col]-'0');
				
				for(i=-1;i<=1;i++)
					for(j=-1;j<=1;j++)
					{
						if(!i && !j)
							continue;
						if(u.row+i<0 || u.row+i>=r || u.col+j<0 || u.col+j>=c)
							continue;
						v.row=u.row+i;
						v.col=u.col+j;
						if(temp.rr==i && temp.cc==j)
						{
							if(u.cost<dis[v.row][v.col])
								dis[v.row][v.col]=v.cost=u.cost,dq.push_front(v);
						}
						else
						{
							if(u.cost+1<dis[v.row][v.col])
								dis[v.row][v.col]=v.cost=u.cost+1,dq.push_back(v);
						}
					}
			}
			printf("%d\n",dis[dr][dc]);
		}
	}
	return 0;
}