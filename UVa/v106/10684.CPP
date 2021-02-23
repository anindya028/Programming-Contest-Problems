#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,*num,max,runsum,i;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		num=(int *)calloc(n,sizeof(int));
		for(i=runsum=max=0;i<n;i++)
		{
			scanf("%d",&num[i]);
                        runsum+=num[i];
			if(runsum>max)max=runsum;
			if(runsum<0)runsum=0;
		}
		if(max>0)printf("The maximum winning streak is %d.\n",max);
		else printf("Losing streak.\n");
		free(num);
	}
	return 0;
}













