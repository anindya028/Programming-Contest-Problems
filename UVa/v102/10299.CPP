//Number Theory
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 20000
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[10000];
prime p[size];
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
	long m=gene(size*2);
	long n,*fact,factor[9],i,b,j,k;
	long double count,countby;
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		else if(n==1)printf("0\n");
		else
                {
			fact=(long *)calloc(m,sizeof(long));
			for(i=0,b=n,j=0;(b!=1)&&(i<m);i++)
			{
				while(b%pr[i]==0)
				{
					fact[i]++;
					b/=pr[i];
				}
				if(fact[i])
				{
					factor[j]=pr[i];
					j++;
				}
			}
			if(b!=1)
			{
				factor[j]=b;
				j++;
			}
			for(count=n,k=0,countby=1;k<j;k++)
			{
				count*=(factor[k]-1);
				countby*=factor[k];	
			}
			printf("%ld\n",(long)(count/countby));
                	free(fact);
		}
        }
}














