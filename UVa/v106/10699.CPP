#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 1000
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[168];
prime p[500];
long gene(long n)
{
	int root=ceil(sqrt(n));
        long i,j;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2].m)
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2].m=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i].m)
                {
			pr[j]=i*2+1;
			j++;
                }
	}
        return j;
}
void main()
{
	long m=gene(size);
	long n,temp,root,fact,j,count;
	while(scanf("%ld",&n)==1)
        {
		if(!n)break;
		temp=n;
		root=ceil(sqrt(n));
		for(j=0,count=0;(temp!=1)&&(j<m);j++)
		{
			if(pr[j]>root)break;
                	fact=0;
			while(temp%pr[j]==0)
			{
				fact++;
				temp/=pr[j];
			}
			if(fact)count++;
		}
		if(temp!=1)count++;
		printf("%ld : %ld\n",n,count);
	}

                	
}













