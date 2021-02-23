#include<stdio.h>

#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,(a))

double dp[22][22][705];

double make(int ev1,int ev2,int at,int d,int n)
{
	if(ev1<=0)
		return 0.;
	if(ev2<=0)
		return 1.;
	if(n==0)
		return 0.;
	if(dp[ev1][ev2][n]>-1.)
		return dp[ev1][ev2][n];
	dp[ev1][ev2][n]=(at/6.)*make(ev1+d,ev2-d,at,d,n-1)+((6-at)/6.)*make(ev1-d,ev2+d,at,d,n-1);
	return dp[ev1][ev2][n];
}

int main()
{
	int ev1,ev2,at,d,i,j,k,l,m;
	while(scanf("%d%d%d%d",&ev1,&ev2,&at,&d)==4 && ev1 && ev2 && at)
	{
		For(i,1,ev1+ev2+2)
			For(j,1,ev1+ev2+2)
				For(m,1,702)
					dp[i][j][m]=-1.;
		printf("%.1lf\n",make(ev1,ev2,at,d,701)*100.);
	}
	return 0;
}