#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
double dp[11][105];
int k;
double make(int a,int len)
{
	if(a<0 || a>k)
		return 0.0;
	if(len==1)
		return 1.0;
	if(dp[a][len])
		return dp[a][len];
	dp[a][len]=make(a-1,len-1)+make(a,len-1)+make(a+1,len-1);
	return dp[a][len];
}
int main()
{
	int i,n,j;
	double sum;
	while(scanf("%d%d",&k,&n)==2)
	{
		for(i=0;i<=k;i++)
			for(j=0;j<=n;j++)
				dp[i][j]=0;
		for(i=sum=0;i<=k;i++)
			sum+=make(i,n);
		printf("%.5lf\n",(sum*100)/pow((double)(k+1),(double)n));
	}
	return 0;
}













