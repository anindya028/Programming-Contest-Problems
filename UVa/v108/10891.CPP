#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 2100000000
#define max(a,b) ((a>b)?(a):(b))
int num[105],sum[105],mat[105][105],n;
int make(int i,int j)
{
	int k,got=-inf;
	if(j<i)return 0;
	if(mat[i][j]>-inf)
		return mat[i][j];
	if(j==i)
	{
		mat[i][j]=num[i];
		return mat[i][j];
	}
	for(k=i;k<=j;k++)
	{
		if(i)got=max(got,sum[j]-sum[i-1]-make(k+1,j));
		else got=max(got,sum[j]-make(k+1,j));
	}
	for(k=j;k>=i;k--)
	{
		if(i)got=max(got,sum[j]-sum[i-1]-make(i,k-1));
		else got=max(got,sum[j]-make(i,k-1));
	}
	mat[i][j]=got;
	return mat[i][j];
}
int main()
{
	int i,j;
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		sum[0]=num[0];
		for(i=1;i<n;i++)
			sum[i]=sum[i-1]+num[i];
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				mat[i][j]=-inf;
		printf("%d\n",2*make(0,n-1)-sum[n-1]);
	}
	return 0;
}













