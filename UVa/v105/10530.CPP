#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
int main()
{
	int n,low,high,flag,zero;
	char res[15];
	char l[]={"too low"};
	char h[]={"too high"};
	char r[]={"right on"};
	while(1)
	{
        	zero=0;
		flag=1;
		low=0;
                high=0;
		while(scanf("%d",&n)==1)
		{
			
			if(!n)
			{       
				zero=1;
				break;
			}
			gets(res);
			gets(res);
			if(!strcmp(l,res))
			{
				if(n>low)low=n;
				if(high&&n>=high)
					flag=0;
			}
			else if(!strcmp(h,res))
			{
				if(!high)high=n;
				else if(n<high)high=n;
				if(low&&n<=low)
					flag=0;
			}
			else 
			{
				if(low&&n<=low)flag=0;
				if(high&&n>=high)flag=0;
				break;
                        }

		}
		if(zero)break;
		if(flag)printf("Stan may be honest\n");
		else printf("Stan is dishonest\n");
        }
	return 0;
}













