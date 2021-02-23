#include<stdio.h>
#include<string.h>

#define LL long long

LL dp[201][201][21][2];

LL make(int n,int m,int k,int is)
{
	if(m<0 || k<0)
		return 0;
	if(m+k/2+(is*(k%2))>n)
		return 0;
	if(!n)
		return (!m && !k);
	if(!m)
		return (is && k==1);
	if(!k)
		return 0;
	if(dp[n][m][k][is]!=-1)
		return dp[n][m][k][is];
	dp[n][m][k][is]=0;
	int i;
	for(i=1;i<=n;i++)
		dp[n][m][k][is]+=make(n-i,m-(!is)*i,k-1,!is);
	return dp[n][m][k][is];
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)==3)
		printf("%lld\n",make(n,m,k,0)+make(n,m,k,1));
	return 0;
}