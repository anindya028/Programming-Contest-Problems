#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,r,c,r1,r2,c1,c2,t,p,mat[105][105],sum[105][105],i,j;
	int max,runsum,inf=-11111;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{       	
		scanf("%d",&n);
		for(r=1;r<=n;r++)
			for(c=1;c<=n;c++)
                        	mat[r][c]=1;
		scanf("%d",&p);
		for(j=0;j<p;j++)
		{
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			for(r=r1;r<=r2;r++)
				for(c=c1;c<=c2;c++)
					mat[r][c]=inf;
        }
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
		if(max>0)printf("%d\n",max);
		else  printf("0\n");
	}
	return 0;
}













