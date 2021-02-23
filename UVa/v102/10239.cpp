#include<stdio.h>

#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))

int n;
int tw,h[1005],w[1005],dp[1005];

int make(int pos)
{
	if(pos==n)
		return 0;
	if(dp[pos]>-1)
		return dp[pos];
	dp[pos]=2000000000;
	int i;
	int now,hp=0,rw=0;
	for(i=pos;i<n;i++)
	{
		rw+=w[i];
		if(rw>tw)
			break;
		hp=Max(hp,h[i]);
		now=hp+make(i+1);
		dp[pos]=Min(dp[pos],now);
	}
	return dp[pos];
}

int main()
{
	int i;
	double hh,ww;
	while(scanf("%d%lf",&n,&ww)==2 && n)
	{
		tw=(int)(ww*10000+1e-8);
		for(i=0;i<=n;i++)
			dp[i]=-1;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&hh,&ww),h[i]=(int)(hh*10000+1e-8),w[i]=(int)(ww*10000+1e-8);
		printf("%.4lf\n",make(0)/10000.0);
	}
	return 0;
}