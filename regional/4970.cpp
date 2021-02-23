#pragma warning ( disable : 4786)
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<map>

using namespace std;

#define mabs(a) ((a)>0?(a):-(a))
#define inf 1<<29
#define Min(a,b) ((a)<(b)?(a):(b))
#define LL long long

struct point
{
	LL x,y;
	point(){}
	point(int _x,int _y){x=_x,y=_y;}
}s[20],g[20];

int n;
LL cost[20][20],dp[1<<18];

LL make(int now,int pos)
{
	if(pos==n)
		return 0;
	if(dp[now]!=-1)
		return dp[now];
	dp[now]=inf;
	dp[now]*=inf;
	int i;
	LL j;
	for(i=0;i<n;i++)
		if(!(now & 1<<i))
		{
			j= cost[pos][i]+make(now | (1<<i),pos+1);
			dp[now]=Min(dp[now],j);
		}
	return dp[now];
}

LL calc(LL dr,LL dc)
{
	if(dr<dc)
		swap(dr,dc);
	if (dr == 0 && dc == 0) return 0;
    if (dr == 1 && dc == 0) return 3;
    if (dr == 2 && dc == 2) return 4;
	if(dr>=2*dc)
		return dr/2 + (dr/2-dc)%2 + dr%2;
	return (dr+dc)/3 + (dr+dc)%3;
}

int main()
{
	int i,j,cs=0;

	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%lld%lld",&s[i].x,&s[i].y);
		for(i=0;i<n;i++)
			scanf("%lld%lld",&g[i].x,&g[i].y);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				LL dx=mabs(s[i].x-g[j].x);
				LL dy=mabs(s[i].y-g[j].y);
				cost[i][j]=calc(dx,dy);

			//	printf("%d %d %d\n",i,j,cost[i][j]);
			}
		memset(dp,-1,sizeof(dp));
		printf("%d. %lld\n",++cs,make(0,0));
	}
	return 0;
}
