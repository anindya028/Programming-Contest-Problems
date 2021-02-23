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
#define mod 1000000007

int dp[11][1024][105],n,m;

int make(int rem,int prev,int state)
{
	if(!rem)
		if(state==((1<<n)-1))
			return 1;
		else
			return 0;
	if(dp[prev][state][rem]!=-1)
		return dp[prev][state][rem];
	int ans=0;
	if(state==((1<<n)-1))
		ans++;
	if(prev<(n-1))
		ans=(ans+make(rem-1,prev+1,(state | (1<<(prev+1)))))%mod;
	if(prev>0)
		ans=(ans+make(rem-1,prev-1,(state | (1<<(prev-1)))))%mod;
	dp[prev][state][rem]=ans;
	return ans;
}

int main()
{
	int i,t,cs,ans,j,k;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d%d",&n,&m);
		if(m<n)
		{
			printf("0\n");
			continue;
		}
		if(m==n)
		{
			printf("1\n");
			continue;
		}
		Foro(i,n)
			Foro(j,1<<n)
				Foro(k,m)
					dp[i][j][k]=-1;
		ans=0;
		For(i,1,n)
			ans=(ans+make(m-1,i,1<<i))%mod;
		printf("%d\n",ans);
	}
	return 0;
}