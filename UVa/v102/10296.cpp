#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
#define mem(a) memset(a,-1,sizeof(a))
#define Min(a,b) (((a)<(b))?(a):(b))

int dp[1<<17],n;
int mat[17][17],st;

int make(int now)
{
	if(now==((1<<n) -1))
		return 0;
	if(dp[now]!=-1)
		return dp[now];
	dp[now]=100000000;
	int i,j,t;
	Foro(i,n)
		if(!(now & 1<<i))
			break;
	For(j,i+1,n)
		if(!(now & 1<<j))
		{
			t=make(now | 1<<i | 1<<j);
			t+=mat[i][j];
			dp[now]=Min(dp[now],t);
		}
	return dp[now];
}

int main()
{
	int i,j,k,u,v,c,m,ans,tot,deg[20],now;
	while(scanf("%d",&n)==1 && n)
	{
		scanf("%d",&m);
		Foro(i,n)
		{
			Foro(j,n)
				mat[i][j]=1000000000;
			deg[i]=0;
		}
		tot=0;
		Foro(i,m)
			scanf("%d%d%d",&u,&v,&c),u--,v--,mat[u][v]=mat[v][u]=Min(mat[u][v],c),
			tot+=c,deg[u]++,deg[v]++;
		Foro(k,n)
			Foro(i,n)
				Foro(j,n)
					mat[i][j]=Min(mat[i][j],mat[i][k]+mat[k][j]);
		mem(dp);
		now=0;
		Foro(i,n)
			if(!(deg[i]%2))
				now|=(1<<i);
		ans=make(now);
		printf("%d\n",ans+tot);
	}
	return 0;
}