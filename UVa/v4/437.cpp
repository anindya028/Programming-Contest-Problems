#include<stdio.h>
#include<vector>
using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

vector<int> adj[205];
int dp[205];
struct block
{
	int x,y,z;
	void ini(int xx,int yy,int zz){x=xx,y=yy,z=zz;}
}bk[205];

int make(int now)
{
	if(SZ(adj[now])==0)
		return bk[now].z;
	if(dp[now]!=-1)
		return dp[now];
	int i,d;
	Forc(i,adj[now])
		d=make(adj[now][i]),
		dp[now]=Max(dp[now],bk[now].z+d);
	return dp[now];
}

int main()
{
	int n,i,j,a,b,c,ans,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		Foro(i,n*6)
			dp[i]=-1,adj[i].clear();
		j=0;
		Foro(i,n)
			scanf("%d%d%d",&a,&b,&c),
			bk[j++].ini(a,b,c),
			bk[j++].ini(b,a,c),
			bk[j++].ini(b,c,a),
			bk[j++].ini(c,b,a),
			bk[j++].ini(c,a,b),
			bk[j++].ini(a,c,b);
		n*=6;
		Foro(i,n)
			Foro(j,n)
				if(bk[i].x>bk[j].x && bk[i].y>bk[j].y)
					adj[i].push_back(j);
		ans=0;
		Foro(i,n)
			a=make(i),
			ans=Max(a,ans);
		printf("Case %d: maximum height = %d\n",++cs,ans);
	}
	return 0;
}