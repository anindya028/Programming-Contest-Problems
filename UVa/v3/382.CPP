#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
int main()
{
	printf("PERFECTION OUTPUT\n");
	long n,i,sum;
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		if(n==1)
		{
			printf("%5ld  DEFICIENT\n",n);
			continue;
		}
        	sum=1;
		for(i=2;i*i<=n;i++)
		{
			if((i*i)==n)sum+=i;
			else if(n%i==0)sum+=(i+n/i);
		}
		if(sum==n)printf("%5ld  PERFECT\n",n);
		else if(sum<n)printf("%5ld  DEFICIENT\n",n);
		else printf("%5ld  ABUNDANT\n",n);
	}
	printf("END OF OUTPUT\n");
	return 0;
}













