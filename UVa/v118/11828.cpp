#include<stdio.h>
#include<string.h>

#define LL long long 
#define mod 1000000000
#define Min(a,b) (((a)<(b))?(a):(b))

char s[1005];
LL dp[505][1005];

LL make(int len,int rem)
{
	if(!len && !rem)
		return 1;
	if(!len || rem<=0)
		return 0;
	if(dp[len][rem]!=-1)
		return dp[len][rem];
	dp[len][rem] = ( 2*make(len-1,rem-1) + 24*make(len-1,rem-2))%mod;
	return dp[len][rem];
}

LL dp2[505][1005][2];

LL make2(int len,int rem,int odd)
{
	if(len==1 && odd)
	{
		if(rem==1)
			return 25;
		if(!rem)
			return 1;
		return 0;
	}
	if(!len && !rem)
		return 1;
	if(!len || rem<0)
		return 0;
	if(dp2[len][rem][odd]!=-1)
		return dp2[len][rem][odd];
	dp2[len][rem][odd]=( make2(len-1,rem,odd) + 25*make2(len-1,rem-2,odd) )%mod;
	return dp2[len][rem][odd];
}

int main()
{
	int t,k,n,cs;
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	scanf("%d",&t);
	
	int i,match,mis;
	for(cs=1;cs<=t;cs++)
	{
		scanf("%d%d%s",&n,&k,s);
	
		LL ans=0;
		for(i=match=mis=0;i<n/2;i++)
			if(s[i]==s[n-i-1])
				match++;
			else
				mis++;
		if(n%2)
			match++;
		LL cum[1005];
		cum[0]=1;
		for(i=1;i<=k;i++)
			cum[i]= (make2(match,i,n%2) + cum[i-1])%mod;
		for(i=0;i<=k;i++)
			ans =( ans + ( make(mis,i) * cum[k-i] ) %mod )%mod;

		printf("Case %d: %lld\n",cs,ans);
	}
	return 0;
}