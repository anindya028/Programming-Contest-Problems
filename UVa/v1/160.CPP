#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int i,num,count[25],temp;
int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
void main()
{
	while(scanf("%d",&num)==1)
	{
		if(!num)break;
		for(i=0;i<25;i++)
		{
			count[i]=0;
                }
		for(i=0;(prime[i]<=num)&&(i<25);i++)
		{
			temp=num;
			while(temp)
			{
				count[i]+=temp/=prime[i];
			}
		}
                printf("%3d! =",num);
		for(i=0;(prime[i]<=num)&&(i<15);i++)
		{
			printf("%3d",count[i]);
		}
                printf("\n");
		for(;(prime[i]<=num)&&(i<25);i++)
		{
			if(i==15)printf("%9d",count[i]);
                        else printf("%3d",count[i]);
		}
		if(i>15)printf("\n");
	}
}               













