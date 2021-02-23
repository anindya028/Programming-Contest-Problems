#include<stdio.h>
#include<string.h>

#define LL long long
#define mem(a) memset(a,-1,sizeof(a))

int freq[60],n;
LL dp[60][60];

LL make(int pos,int rem)
{
	if(rem<0)
		return 0;
	if(pos==(n+1))
		return !rem;
	if(dp[pos][rem]!=-1)
		return dp[pos][rem];
	dp[pos][rem]=0;
	int i;
	for(i=0;i<=freq[pos];i++)
		dp[pos][rem]+=make(pos+1,rem-i);
	return dp[pos][rem];
}

int main()
{
	int m,i,j,cs=0;
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		printf("Case %d:\n",++cs);
		for(i=1;i<=n;i++)
			freq[i]=0;
		for(i=1;i<=n;i++)
			scanf("%d",&j),freq[j]++;
		mem(dp);
		for(i=0;i<m;i++)
		{
			scanf("%d",&j);
			printf("%lld\n",make(1,j));
		}
	}
	return 0;
}
