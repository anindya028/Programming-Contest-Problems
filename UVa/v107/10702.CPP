//Graph + DP
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1<<28
 
int dp[1005][105],adj[105][105];

int main()
{
	int c,s,e,t,i,j,k,mx;
	while(scanf("%d%d%d%d",&c,&s,&e,&t)==4)
	{
		if(!c)break;
		for(i=1;i<=c;i++)
			for(j=1;j<=c;j++)
				scanf("%d",&adj[i][j]);
		for(i=1;i<=c;i++)
			dp[0][i]=-inf;
		dp[0][s]=0;
		for(i=1;i<=t;i++)
			for(j=1;j<=c;j++)
			{
				mx=-inf;
				for(k=1;k<=c;k++)
					mx=Max(mx,dp[i-1][k]+adj[k][j]);
				dp[i][j]=mx;
			}
		mx=-inf;
		for(i=0;i<e;i++)
		{
			scanf("%d",&k);
			mx=Max(mx,dp[t][k]);
		}
		printf("%d\n",mx);
	}
	return 0;
}

