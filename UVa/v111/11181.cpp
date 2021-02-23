#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<map>
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

bool is[25];
double dp[25][25],p[25];
int n;

double make(int now,int rem)
{
	if(now==n)
	{
		if(!rem)
			return 1.;
		else
			return 0;
	}
	if(dp[now][rem]>-1)
		return dp[now][rem];
	dp[now][rem]=0.;
	if(is[now])
	{
		if(rem)
			dp[now][rem]+=p[now]*make(now+1,rem-1);
		dp[now][rem]+=(1-p[now])*make(now+1,rem);
	}
	else
		dp[now][rem]=make(now+1,rem);
	return dp[now][rem];
}

int main()
{
	int i,r,j,k,cs=0;
	double tot;
	while(scanf("%d%d",&n,&r)==2)
	{
		if(!n && !r)
			break;
		Foro(i,n)
			scanf("%lf",&p[i]);
		printf("Case %d:\n",++cs);
		if(!r)
		{
			tot=0;
			Foro(i,n)
				printf("%.6lf\n",tot);
			continue;
		}
		Foro(i,n)
		{
			Foro(j,r+1)
				dp[i][j]=-1.;
			is[i]=true;
		}
		tot=make(0,r);
		Foro(k,n)
		{
			Foro(i,n)
			{
				Foro(j,r+1)
					dp[i][j]=-1.;
				is[i]=true;
			}
			is[k]=false;
			printf("%.6lf\n",p[k]*make(0,r-1)/tot);
		}
	}		
	return 0;
}