#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
long long func(long long n)
{
	if(n%2==0)return n/2;
	else return (3*n+1);
}
int main()
{
	unsigned long low,high,i,count,max,ind,temp;
        long long j;
	while(scanf("%lu%lu",&low,&high)==2)
	{
		if(!low&&!high)break;
		if(low>high)
		{
			temp=low;
			low=high;
			high=temp;
		}
                max=0;
		for(i=low;i<=high;i++)
		{
			count=0;
			j=i;
			if(j==1)
			{
				max=3;
				ind=1;
                        }
			else
			{
				while(j>1)
				{
					j=func(j);
					count++;
				}
			}
			if(count>max)
			{
				max=count;
				ind=i;
			}
		}
		printf("Between %lu and %lu, %lu generates the longest sequence of %lu values.\n",low,high,ind,max);
	}
	return 0;
}













