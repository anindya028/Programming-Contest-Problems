#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 50000
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[5133];
prime p[25000];
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
	long n,*fact,root,i,temp,count,back;
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		fact=(long *)calloc(m,sizeof(long));
		temp=labs(n);
		root=ceil(sqrt(temp));
		for(i=0,count=0;(pr[i]<=root)&&(temp>1);i++)
		{
			while(temp%pr[i]==0)
			{
				fact[i]++;
				count++;
				temp/=pr[i];
			}
		}
		if(temp!=1)
		{
			count++;
                }
                printf("%ld =",n);
		if(n<0)printf(" -1 x");
		back=0;
		if(temp==labs(n))printf(" %ld",labs(n));
		else
		{
			for(i=0;pr[i]<=root;i++)
			{
				while(fact[i])
				{
					fact[i]--;
					back++;
					if(back==count)printf(" %ld",pr[i]);
					else printf(" %ld x",pr[i]);
				}
			}
                        if(temp!=1)printf(" %ld",temp);
		}
		printf("\n");
                free(fact);
        }

}













