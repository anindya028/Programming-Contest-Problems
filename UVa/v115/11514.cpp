#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;

#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1<<30
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

map<string,int> power;
char s[105],buf[200005];
int p,v,pe[1005],af[1005],df[1005];
bool adj[1005][1005];
int dp[1005][1005];

int make(int nowp,int nowv)
{
	if(nowv==v)
		return 0;
	if(nowp==p)
		return inf;
	if(dp[nowp][nowv]!=-1)
		return dp[nowp][nowv];
	int a=inf,b=inf;
	a=make(nowp+1,nowv);
	if(adj[nowp][nowv] && af[nowp]>=df[nowv])
		b=pe[nowp]+make(nowp+1,nowv+1);
	dp[nowp][nowv]=Min(a,b);
	return dp[nowp][nowv];
}

int main()
{
	int i,e,j,tot,bs,dbs;	
	string ss;
	while(scanf("%d%d%d",&p,&v,&e)==3)
	{
		if(!p && !v && !e)
			break;
		power.clear();
		Foro(i,p)
			scanf("%s%d%d",s,&af[i],&pe[i]),ss=s,power[ss]=i;
		Foro(i,p)
			Foro(j,v)
				adj[i][j]=false,dp[i][j]=-1;
		Foro(i,v)
		{
			scanf("%s%d%s",s,&df[i],buf);
			for(j=0;buf[j];++j)
				if(buf[j]==',')
					buf[j]=' ';
			bs=dbs=0;
			while(sscanf(buf+bs,"%s%n",&s,&dbs)==1)
				ss=s,adj[power[ss]][i]=true,bs+=dbs;
		}
		tot=make(0,0);
		if(tot<=e)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}