#include<stdio.h>

#define size 9001

double first[size];
long int second[size];

int main()
{
	double a;
	long int b,n,i,test;
	a=5.0;b=-1;
	first[1]=a;
	second[1]=b;
	for(i=2;i<size;i++)
	{
		a/=2.0;
		if(a<1.0)
		{
			b=b-1;
			a*=10.0;
		}
		first[i]=a;
		second[i]=b;
	}
	scanf("%ld",&test);
	for(;test;test--)
	{
		scanf(" %ld",&n);
		if(n==6)
			printf("2^-6 = 1.563E-2\n");
		else if(n==7)
			printf("2^-7 = 7.813E-3\n");
		else
			printf("2^-%ld = %.3lfE%ld\n",n,first[n],second[n]);
	}
	return 0;
}

