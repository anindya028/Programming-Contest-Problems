#include<stdio.h>
#include<algorithm>
using namespace std;

#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,a)
#define inf 1<<29
#define Max(a,b) (((a)>(b))?(a):(b))

bool comp(int a,int b)
{
	return a>b;
}

int n,adj[1005][3],tian[1005],king[1005];
int dp[1005][1005];

int make(int t,int k)
{
	int a=-inf,b=-inf,c=-inf,i;
	if(k==n)
		return (t-n)*200;
	if(dp[t][k]!=-inf)
		return dp[t][k];
	i=k;
	if(king[i]>tian[t])
		a=-200+make(t+1,k+1);
	while(i<n && king[i]>tian[t])
		i++;
	if(i<n && king[i]==tian[t])
		b=make(t+1,i+1),i++;
	while(i<n && king[i]>=tian[t])
		i++;
	if(i<n && king[i]<tian[t])
		c=200+make(t+1,i+1);
	dp[t][k]=Max(a,Max(b,c));
	return dp[t][k];
}

int main()
{
	int i,j;
	while(scanf("%d",&n)==1 && n)
	{
		Foro(i,n)
			scanf("%d",&tian[i]);
		Foro(i,n)
			scanf("%d",&king[i]);
		sort(tian,tian+n,comp);
		sort(king,king+n,comp);
		Foro(i,n)
			Foro(j,n)
				dp[i][j]=-inf;
		printf("%d\n",make(0,0));
	}
	return 0;
}