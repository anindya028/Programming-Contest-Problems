//2-D knapsack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

#define inf 1<<29
#define Min(a,b) (((a)<(b))?(a):(b))
#define size 305

int dp[size][size];

struct coin
{
	int x,y;
}c[50];

int main()
{
	int n,s,t,mn;
	register int i,j,k;
	double l,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&s);
		for(i=0;i<n;++i)
			scanf("%d%d",&c[i].x,&c[i].y);
		for(i=0;i<s+2;++i)
			for(j=0;j<s+2;++j)
				dp[i][j]=inf;
		dp[0][0]=0;
		for(i=0;i<n;++i)
			for(j=0;j<s+2;++j)
				for(k=0;k<s+2;++k)
					if(dp[j][k]<inf)
						if(j+c[i].x<(s+2) && k+c[i].y<(s+2))
							dp[j+c[i].x][k+c[i].y]=Min(dp[j+c[i].x][k+c[i].y],dp[j][k]+1);
		mn=inf;
		for(i=0;i<=s;++i)
		{
			m=sqrt(s*s-i*i);
			l=floor(m+1e-8);
			if(fabs(l-m)<1e-8)
				mn=Min(mn,dp[i][(int)l]);
		}
		if(mn==inf)
			printf("not possible\n");
		else
			printf("%d\n",mn);
	}
	return 0;
}
