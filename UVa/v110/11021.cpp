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

double dp[1005][1005];
double p[1005];
int n;

double make(int k,int m)
{
	if(dp[k][m]>-1)
		return dp[k][m];
	int i;
	if(k!=1)
		dp[k][m]=pow(make(1,m),(double)k);
	else
	{
		dp[1][m]=0.;
		Foro(i,n)
			dp[1][m]+=p[i]*make(i,m-1);
	}
	return dp[k][m];
}

int main()
{
	int k,m,t,cs,i,j;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d%d%d",&n,&k,&m);
		Foro(i,n)
			scanf("%lf",&p[i]);
		Foro(i,Max(n+1,k+1))
			Foro(j,m+1)
				dp[i][j]=-1;
		Foro(i,m+1)
			dp[0][i]=1.;
		For(i,1,Max(n+1,k+1))
			dp[i][0]=0;
		printf("Case #%d: %.7lf\n",cs+1,make(k,m));
	}
	return 0;
}
