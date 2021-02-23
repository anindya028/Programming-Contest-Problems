#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
long mat[110][110];
long sum[110][110];
int main()
{
	int n,r,c,c1;
	long max,runsum,inf=-1147483647;
	scanf("%d",&n);
	for(r=1;r<=n;r++)
		for(c=1;c<=n;c++)
			scanf("%ld",&mat[r][c]);
	for(r=1;r<=n;r++)
		for(c=1;c<=n;c++)
			sum[r][c]=mat[r][c]+sum[r][c-1];
	max=inf;
	for(c=1;c<=n;c++)
	{
		for(c1=c;c1<=n;c1++)
		{
			runsum=0;
			for(r=1;r<=n;r++)
			{
				runsum+=sum[r][c1]-sum[r][c-1];
				if(runsum>max)max=runsum;
				if(runsum<0)runsum=0;
			}
		}
	}
	printf("%ld\n",max);
	return 0;
}













