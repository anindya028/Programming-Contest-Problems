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
//#define Long __int64
#define Long long long
int n;
Long dp[22][22];

Long make(int i,int j)
{
	Long mx=0,mx1=0;
	int k;
	if(i==n && j==0)
		return 0;
	if(dp[i][j]>-1)
		return dp[i][j];
	if(i<j)
	{
		For(k,i,j)
			mx=Max(mx,make(i,k)+make(k+1,j));
		dp[i][j]=mx;
		return mx;
	}
	Fore(k,i+1,n)
		mx=Max(mx,make(k,1)+make(k,j));
	For(k,1,j)
		mx1=Max(mx1,make(i,k)+make(n,k));
	dp[i][j]=mx+mx1;
	return dp[i][j];
}

int main()
{
	int i,j,k;
	while(scanf("%d%d",&n,&k)==2)
	{
		Fore(i,0,n)
			Fore(j,0,n)
				dp[i][j]=-1;
		dp[n][1]=k;
		printf("%lld\n",make(1,n));
	}
	return 0;
}
