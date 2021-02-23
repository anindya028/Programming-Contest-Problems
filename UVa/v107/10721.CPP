#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Long __int64
//#define Long long long
Long dp[55][55][55][2];
Long det(Long n,Long k,Long m,int f)
{
	int i;
	if(n<1 || k<1 || k>n)
		return 0;
	if(dp[n][k][m][f]>=0)
		return dp[n][k][m][f];
	if(k==1 && m==n)
	{
		if(f)dp[n][k][m][f]=1;
		else dp[n][k][m][f]=0;
		return dp[n][k][m][f];
	}
	dp[n][k][m][f]=0;
	for(i=1;i<=m;i++)
	{
		dp[n][k][m][f]+=det(n-i,k-1,m,(!f));
	//	if(i!=m)dp[n][k][m][f]+=det(n,k,i,f);
	}
	return dp[n][k][m][f];
}
int main()
{
	int i,j,k,n,m;
	for(i=0;i<54;i++)
		for(j=0;j<54;j++)
			for(k=0;k<54;k++)
				dp[i][j][k][0]=dp[i][j][k][1]=-1;
	for(i=1;i<53;i++)
		for(j=1;j<53;j++)
			if(j>=i)
				dp[i][1][j][1]=1;
	while(scanf("%d%d%d",&n,&k,&m)==3)
	{
		if(k%2==0)printf("%I64d\n",det(n,k,m,0));
		else printf("%I64d\n",det(n,k,m,1));
	}
	return 0;
}













