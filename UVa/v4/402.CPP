#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int *sol,n,x,count,card[20],i,j,countp,cs=0,printed;
	while(scanf("%d%d",&n,&x)==2)
	{
		sol=(int *)calloc(n,sizeof(int));
		x=n-x;
		for(i=0;i<20;i++)scanf("%d",&card[i]);
		for(i=printed=count=0;i<20 && count<x;i++)
		{
			for(j=countp=0;j<n;j++)
			{
				if(!sol[j])countp++;
				if(countp==card[i])
				{
					sol[j]=1;
					count++;
					countp=0;
				}
				if(count==x)break;
			}
		}
		printf("Selection #%d\n",++cs);
        for(i=0;i<n;i++)  
		{
			if(!sol[i])
			{
				if(printed)printf(" ");
				printf("%d",i+1);
				printed=1;
			}
		}
		printf("\n\n");
	}
	return 0;
}













