#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long

struct mybig
{
	LL fir,sec;
}dp[70][2][2],zero;

LL dp2[70][2],mod;

mybig add(mybig a,mybig b)
{
	mybig ret;
	ret.sec=(a.sec+b.sec)%mod;
	ret.fir=(a.fir+b.fir)+(a.sec+b.sec)/mod;
	return ret;
}

char s[100];

LL make2(int pos,int eq)
{
	if(!s[pos])
		return 1;
	if(dp2[pos][eq]!=-1)
		return dp2[pos][eq];
	dp2[pos][eq]=make2(pos+1,(eq && s[pos]=='0'));
	if(!(eq && s[pos]=='0'))
		dp2[pos][eq]+=make2(pos+1,(eq && s[pos]=='1'));
	return dp2[pos][eq];
}

mybig make(int pos,int eq,int prev)
{
	if(!s[pos])
		return zero;
	if(dp[pos][eq][prev].sec!=-1)
		return dp[pos][eq][prev];
	
	dp[pos][eq][prev]=make(pos+1,(eq && s[pos]=='0'),0);

	if(!(eq && s[pos]=='0'))
	{
		mybig a,b;
		a.sec=prev*make2(pos+1,(eq && s[pos]=='1'));
		a.fir=0;
		b=add(a,make(pos+1,(eq && s[pos]=='1'),1));
		dp[pos][eq][prev]=add(dp[pos][eq][prev],b);
	}
	return dp[pos][eq][prev];
}

int main()
{
	LL n;
	int i,cs=0;
	mod=1e9;
	mod*=mod;
	zero.fir=zero.sec=0;
	while(scanf("%lld",&n)==1 && n>=0)
	{
		if(n<2)
		{
			printf("Case %d: 0\n",++cs);
			continue;
		}
		i=0;
		while(n)
		{
			s[i++]=(n%2)+'0';
			n/=2;
		}
		s[i]=0;
		reverse(s,s+strlen(s));
		mem(dp,-1);
		mem(dp2,-1);
		mybig ans=add( make(1,0,0) , make(1,1,1));
		if(!ans.fir)
			printf("Case %d: %lld\n",++cs,ans.sec);
		else
			printf("Case %d: %lld%.18lld\n",++cs,ans.fir,ans.sec);
	}
	return 0;
}