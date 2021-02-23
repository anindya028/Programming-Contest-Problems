#include<stdio.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1<<29

int dp[11][102][102];

int make(int rem,int st,int nd)
{
	if(rem==1)
		return ((nd*(nd+1))/2 - (st*(st-1))/2);
	if(st>nd)
		return 0;
	if(dp[rem][st][nd]!=-1)
		return dp[rem][st][nd];
	
	dp[rem][st][nd]=inf;

	int i,j;
	for(i=st;i<=nd;i++)
		j=make(rem,i+1,nd),
		j=Max(j,make(rem-1,st,i-1)),
		j+=i,
		dp[rem][st][nd]=Min(dp[rem][st][nd],j);

	return dp[rem][st][nd];
}

int main()
{
	int t,n,m;
	mem(dp,-1);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",make(n,1,m));
	}
	return 0;
}