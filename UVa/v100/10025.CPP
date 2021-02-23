#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long n,i,j=0,sum,m;
	scanf("%ld",&m);
	for(j=0;j<m;j++)
	{
		if(j)printf("\n");
		scanf("%ld",&n);
        	n=labs(n);
		for(i=1;;i++)
		{
			sum=i*(i+1)/2;
			if(sum>=n)
			{
				if((sum-n)%2==0)
				{
					printf("%ld\n",i);
                                        break;
				}
			}
                }
        }
	return 0;
}













