#include<stdio.h>
#include<string.h>

#define LL long long
#define mod 1000000007

bool p[1000];
int pr[200];

int gene(int n)
{
	int i,j;
	for(i=2;i*i<=n;i++)
		if(!p[i])
			for(j=i*i;j<=n;j+=i)
				p[j]=1;
	j=0;
	for(i=2;i<n;i++)
		if(!p[i])
			pr[j++]=i;
	return j;
}

LL fr[200];
LL dp[200][2],k;

LL make(int now,int is)
{
	if(fr[now]<k)
		return is;
	if(dp[now][is]!=-1)
		return dp[now][is];
	dp[now][is]=((-fr[now]/(k+1)+fr[now]/k)*make(now+1,1))%mod;
	dp[now][is]=(dp[now][is]+(fr[now]/(k+1) + 1)*make(now+1,is))%mod;
	return dp[now][is];
}

int main()
{
	int m=gene(1000),i,t,cs;
	LL n;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%lld%lld",&n,&k);
		memset(fr,0,sizeof(fr));
		for(i=0;i<m;i++)
		{
			LL temp=n;
			while(temp)
				fr[i]+=temp/=pr[i];
		}
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %lld\n",cs+1,make(0,0));
	}
	return 0;
}