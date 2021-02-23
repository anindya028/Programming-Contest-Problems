#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define LL long long

struct myp
{
	LL fir,sec;
}dp[66][66][67][2],a,b,c;

LL ncr[65][65];
LL C(int n,int r)
{
	if(r>n)
		return 0;
	if(!r || n==r)
		return 1;
	if(ncr[n][r]!=-1)
		return ncr[n][r];
	ncr[n][r]=C(n-1,r)+C(n-1,r-1);
	return ncr[n][r];
}

myp make(int rem,int click,int now,int is)
{
	if(click>rem || click<0)
		return c;
	if(!rem)
	{
		if(!click)
		{
			if(now>0)
				return a;
			else if(now==0)
				return c;
		}
		else
			return c;
	}
	
	if(!now)
	{
		if(!click && is)
			return c;
		b.sec=C(rem-1,click-is);
		return b;
	}
	if(dp[rem][click][now][is].fir!=-1)
		return dp[rem][click][now][is];
	int i;
	myp temp;
	dp[rem][click][now][is].fir=dp[rem][click][now][is].sec=0;
	for(i=1;i<=rem;i++)
		temp=make(rem-i,click-is*i,now-1,!is),
		dp[rem][click][now][is].fir+=temp.fir,
		dp[rem][click][now][is].sec+=temp.sec;
	return dp[rem][click][now][is];
}

int main()
{
	a.fir=1,a.sec=b.fir=c.fir=c.sec=0;
	memset(dp,-1,sizeof(dp));
	memset(ncr,-1,sizeof(ncr));
	int n,m,i,cs=0;
	myp ans,temp;
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		ans.fir=ans.sec=0;
		for(i=m;i<=n;i++)
		{	
			temp=make(n,i,i+1,0),
			ans.fir+=temp.fir,ans.sec+=temp.sec;
			temp=make(n,i,i,1),
			ans.fir+=temp.fir,ans.sec+=temp.sec;
		}
		printf("Case %d: %lld %lld\n",++cs,ans.fir,ans.sec);
	}
	return 0;
}