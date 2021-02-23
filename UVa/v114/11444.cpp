#include<stdio.h>
#include<string.h>

#define LL long long
#define mod 1000000009

LL cum[100005][22],po[100005][22],sumseq[100005],ncr[22][22];
int seq[100005];

LL calc(int n,int r)
{
	if(n==r || !r)
		return 1;
	if(ncr[n][r]!=-1)
		return ncr[n][r];
	ncr[n][r]=(calc(n-1,r)+calc(n-1,r-1))%mod;
	return ncr[n][r];
}

int main()
{
	int t,i,j,k,n,q,a,b,u;
	memset(ncr,-1,sizeof(ncr));
	LL v;
	for(i=1;i<=100000;i++)
	{	
		po[i][0]=1;
		for(j=1;j<=20;j++)
			po[i][j]=(po[i][j-1]*i)%mod;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&seq[i]),sumseq[i]=(sumseq[i-1]+seq[i])%mod;
		for(i=1;i<=n;i++)
			cum[i][1]=(seq[i]*i)%mod;
		for(j=2;j<=20;j++)
			for(i=1;i<=n;i++)
				cum[i][j]=(cum[i][j-1]*i)%mod;
		for(j=1;j<=20;j++)
			for(i=1;i<=n;i++)
				cum[i][j]=(cum[i-1][j]+cum[i][j])%mod;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d",&k,&a,&b);
			if(a==1)
			{
				printf("%lld\n",cum[b][k]);
				continue;
			}
			u=a-1;
			LL F[22];
			F[0]=(sumseq[b]-sumseq[a-1]+mod)%mod;
			for(j=1;j<=k;j++)
			{
				F[j]=(cum[b][j]-cum[a-1][j]+mod)%mod;
				for(i=j-1;i>=0;i--)
					v= (calc(j,i)*po[u][j-i])%mod,
					v= (v*F[i])%mod,
					F[j]=(F[j] - v + mod)%mod;
			}
			printf("%lld\n",F[k]);
		}
	}
	return 0;
}