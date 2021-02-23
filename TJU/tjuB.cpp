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

int num[105],dp[105][105],n;

int make(int now,int k)
{
	if(now==n)
		if(!k)
			return 0;
		else
			return inf;
	if(k<=0)
		return inf;
	if(dp[now][k]>=0)
		return dp[now][k];
	int i,mx=0;
	dp[now][k]=inf;
	for(i=now;i<n;i++)
		mx=Max(mx,num[i]),
		dp[now][k]=Min(dp[now][k],mx+make(i+1,k-1));
	
	return dp[now][k];
}



int main()
{
	int k,i,j;
	while(scanf("%d%d",&n,&k)==2 && n && k)
	{
		Foro(i,n)
			scanf("%d",&num[i]);
		Foro(i,n+1)
			Foro(j,k+1)
				dp[i][j]=-1;
		printf("%d\n",make(0,k));
	}
	return 0;
}