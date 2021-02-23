#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int bytes,i,cs=0,sum,cur;
	while(scanf("%d",&bytes)==1 && bytes)
	{
		
		printf("Output for data set %d, %d bytes:\n",++cs,bytes);
		for(i=sum=0;bytes;i++)
		{
			scanf("%d",&cur);		
			bytes-=cur;
			sum+=cur;
			if(i%5==4)
			{
				if(!sum)printf("   Time remaining: stalled\n");
				else if((bytes*5)%sum)printf("   Time remaining: %d seconds\n",(bytes*5)/sum+1);
				else printf("   Time remaining: %d seconds\n",(bytes*5)/sum);
				sum=0;
			}
		}
		printf("Total time: %d seconds\n",i);
		printf("\n");
	}
	return 0;       

}













