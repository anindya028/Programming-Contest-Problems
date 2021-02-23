
//printf
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
long carm[]={561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};
int main()
{
	long n,i,flag;
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		flag=0;
		for(i=0;i<15;i++)
			if(carm[i]==n)
			{
				printf("The number %ld is a Carmichael number.\n",n);
				flag=1;
				break;
			}
		if(!flag)printf("%ld is normal.\n",n);
        }
	return 0;
}













