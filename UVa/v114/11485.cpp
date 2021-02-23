#include<stdio.h>
#include<math.h>

#define eps 1e-9

int num[1005],n;
long long dp[10][80];

long long make(int rem,int k)
{
	int i;
	if(!rem)
		return k/10;
	if(dp[rem][k]!=-1)
		return dp[rem][k];
	dp[rem][k]=0;
	for(i=0;i<n;i++)
		dp[rem][k]+=make(rem-1,k+num[i]);
	return dp[rem][k];
}

int main()
{
	int i,j;
	double c;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%lf",&c),num[i]=(int)floor((c-floor(c+eps)+eps)*10);
		for(i=0;i<10;i++)
			for(j=0;j<80;j++)
				dp[i][j]=-1;
		printf("%lld\n",make(8,0));
	}
	return 0;
}