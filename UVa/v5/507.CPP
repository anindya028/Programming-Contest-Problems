#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int t,n,*num,runsum,max,start,end,i,j,stemp;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		num=(int *)calloc(n-1,sizeof(int));
		for(j=runsum=max=0,stemp=1;j<(n-1);j++)
		{
			scanf("%d",&num[j]);
                        runsum+=num[j];
			if(runsum>max)
			{
                        	start=stemp;
				max=runsum;
				end=j+2;
			}
			if(runsum==max && stemp==start)
			{
				start=stemp;
				max=runsum;
				end=j+2;
			}
			if(runsum<0)
			{
				runsum=0;
				stemp=j+2;
			}
		}
		if(max>0)printf("The nicest part of route %d is between stops %d and %d\n",i+1,start,end);
		else printf("Route %d has no nice parts\n",i+1);
		free(num);
	}
	return 0;
}













