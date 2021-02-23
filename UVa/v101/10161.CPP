#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n,low,high,x,y;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		low=(int)floor(sqrt(n));
		if(low*low==n)
		{
			if(low%2)printf("1 %d\n",low);
			else printf("%d 1\n",low);
			continue;
		}
		else if(low*low<n)
		{
			high=low+1;
			if(high%2)
			{
				if((high*high-n)<high)
				{
					x=high*high-n+1;
					y=high;
				}
				else 
				{
					x=high;
					y=high-(high*high-high-n+1);
				}
			}
			else
			{
				if((high*high-n)<high)
				{
					x=high;
					y=high*high-n+1;
				}
				else
				{
					x=high-(high*high-n-high+1);
					y=high;
				}
			}
		}
		printf("%d %d\n",x,y);
	}
	return 0;			
}













