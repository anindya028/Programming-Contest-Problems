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
//#define Long long long

int dp[5005][1005];
int n,k,num[5005];

int make(int now,int r)
{
	int mn=inf,i,j;
	if(r==0)
		return 0;
	if(dp[now][r]!=inf)
		return dp[now][r];
	for(i=now;i+(3*r)-1<n;i++)
	{
		dp[i][r]=(num[i]-num[i+1])*(num[i]-num[i+1])+make(i+2,r-1);
		mn=Min(mn,dp[i][r]);
	}
	for(j=i-2;j>=now;j--)
		dp[j][r]=Min(dp[j][r],dp[j+1][r]);
	return mn;
}

int main()
{
	int i,j,T,cs;
	scanf("%d",&T);
	For(cs,0,T)
	{
		scanf("%d%d",&k,&n);
		For(i,0,n)
			scanf("%d",&num[i]);
		k+=8;
		For(i,0,n)
			Fore(j,0,k)
				dp[i][j]=inf;

		printf("%d\n",make(0,k));
	}
	return 0;
}
