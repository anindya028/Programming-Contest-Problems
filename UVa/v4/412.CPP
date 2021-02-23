#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 50
typedef unsigned long int myint;
int gcd(int m,int n)
{
	if(!m)return n;
	return gcd((n%m),m);
}
void main()
{
	int n,num[size],count,j,k;
        double temp;
	while(scanf("%d",&n)==1)
        {
		if(!n)break;
		for(j=0;j<n;j++)
		{
			scanf("%d",&num[j]);
		}
        	count=0;
		for(j=0;j<(n-1);j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(gcd(num[j],num[k])==1)count++;
			}
		}
		if(count)
		{
			temp=3.0*n*(n-1)/count;
			printf("%lf\n",sqrt(temp));
		}
		else printf("No estimate for this data set.\n");
        }
}













