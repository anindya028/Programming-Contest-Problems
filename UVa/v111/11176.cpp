#include<stdio.h>
#include<math.h>

#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,a)

double dp[505][505],p;
int n;

double make(int i,int j)
{
	if(i<=j)
		return 1.;
	if(!j)
		return pow(1-p,i);
	if(dp[i][j]>-1)
		return dp[i][j];
	if(i==j+1)
	{
		dp[i][j]=pow(p,i);
		dp[i][j]=1-dp[i][j];
		return dp[i][j];
	}
	dp[i][j]=make(i-1,j);

	double t=make(i-j-2,j);
	t*=pow(p,j+1);
	t*=(1-p);
	dp[i][j]-=t;

	return dp[i][j];
}

int main()
{
	int i,j;
	double ans,k;
	
	while(scanf("%d%lf",&n,&p)==2 && n)
	{
		Foro(i,n+3)
			Foro(j,n+3)
				dp[i][j]=-1.;
		ans=0;
		for(i=1;i<=n;i++)
		{
//			k=make(n,i);
			ans+=(make(n,i)-make(n,i-1))*i;
		}
		printf("%.6lf\n",ans);
	}

	return 0;
}