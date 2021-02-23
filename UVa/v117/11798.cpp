#include<stdio.h>
#include<string.h>

#define mod 1000000007
#define LL long long

LL ncr[55][55];
LL calc(int n,int r)
{
	if(n==r || !r)
		return 1;
	if(ncr[n][r]!=-1)
		return ncr[n][r];
	ncr[n][r]=(calc(n-1,r)+calc(n-1,r-1))%mod;
	return ncr[n][r];
}

LL dp[405][55][55];
LL make(int n,int rem,int used)
{
	if(!n)
		return !rem;
	if(dp[n][rem][used]!=-1)
		return dp[n][rem][used];
	dp[n][rem][used]= (used*make(n-1,rem,used))%mod;
	if(rem)
		dp[n][rem][used] = (dp[n][rem][used] + rem*make(n-1,rem-1,used+1))%mod;
	return dp[n][rem][used];
}

LL val[55][405];

int main()
{
	int i,n,m,c,t,cs,j;
	LL ans,v;
	for(i=1;i<=50;i++)
	{
		val[i][0]=1;
		for(j=1;j<=402;j++)
			val[i][j] = (val[i][j-1]*i)%mod;
	}
	memset(dp,-1,sizeof(dp));
	memset(ncr,-1,sizeof(ncr));
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d%d",&m,&n,&c);
		m++,n++;
		if(m*n==1)
		{
			printf("Case %d: %d\n",cs+1,c);
			continue;
		}
		ans=0;
		for(i=1;i<c;i++)
			v=calc(c,i),
			v= (v*make((n*m)/2,i,0))%mod,
			v= (v*val[c-i][n*m-(n*m)/2])%mod,
			ans = (ans+v)%mod;
		

		printf("Case %d: %lld\n",cs+1,ans);
	}
	return 0;
}