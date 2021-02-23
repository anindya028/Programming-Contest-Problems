//Number Theory
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 225
int main()
{
	long n,m,fact2,fact5,i,j,temp,digit;
        long f2[]={6,2,4,8};
	while(scanf("%ld%ld",&n,&m)==2)
	{
        	fact2=fact5=0;
		for(i=n-m+1,digit=1;i<=n;i++)
		{
			temp=i;
			while(temp%2==0)
			{
				fact2++;
				temp/=2;
			}
			while(temp%5==0)
			{
				fact5++;
				temp/=5;
			}
			digit=(digit*(temp%10))%10;
		}
		j=fact2-fact5;
		if(j>0)digit=(digit*f2[j%4])%10;
		else if(j<0)digit=5;
		printf("%ld\n",digit);
        }
	return 0;
}













