#include<stdio.h>

double dp[2005][2005],pr[3];

int main()
{
	double dice[2][6];
	int p1,p2,i,j;
	while(scanf("%d%d",&p2,&p1)==2)
	{
		for(i=0;i<6;i++)
			scanf("%lf",&dice[0][i]);
		for(i=0;i<6;i++)
			scanf("%lf",&dice[1][i]);
		pr[0]=pr[1]=pr[2]=0.;
		for(i=1;i<=6;i++)
			for(j=1;j<=6;j++)
			{
				double d=dice[0][i-1]*dice[1][j-1];
				if(i<j)
					pr[0]+=d;
				else if(i>j)
					pr[1]+=d;
				else
					pr[2]+=d;
			}
		for(i=1;i<=p2;i++)
			dp[0][i]=0.;
		for(i=1;i<=p1;i++)
			dp[i][0]=1.;
		for(i=1;i<=p1;i++)
			for(j=1;j<=p2;j++)
				dp[i][j]=pr[0]*dp[i-1][j]+pr[1]*dp[i][j-1],
				dp[i][j]/=(1-pr[2]);
		printf("%.6lf\n",dp[p1][p2]);
	}
	return 0;
}
