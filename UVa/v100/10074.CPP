#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int r,c,mat[105][105],sum[105][105],c1,R,C,max;
	int runsum,inf=-11111;
	while(scanf("%d%d",&R,&C)==2)
	{
		if(!R && !C)break;
		for(r=1;r<=R;r++)
			for(c=1;c<=C;c++)
			{
				scanf("%d",&mat[r][c]);
				if(!mat[r][c])mat[r][c]=1;
				else mat[r][c]=inf;
            }
		for(r=1;r<=R;r++)
			for(c=1;c<=C;c++)
				sum[r][c]=mat[r][c]+sum[r][c-1];
		max=inf;
		for(c=1;c<=C;c++)
		{
			for(c1=c;c1<=C;c1++)
			{
				runsum=0;
				for(r=1;r<=R;r++)
				{
					runsum+=sum[r][c1]-sum[r][c-1];
					if(runsum>max)max=runsum;
					if(runsum<0)runsum=0;
				}
			}
		}
		if(max<0)printf("0\n");
		else printf("%d\n",max);
        }
	return 0;
}













