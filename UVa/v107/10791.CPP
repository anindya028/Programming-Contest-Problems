#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 23200
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[4796];
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
	long n,i=1,*nfact,j,freq,k,root,temp,count;
	unsigned long sum;
	long m=gene(46400);
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		nfact=(long *)calloc(m,sizeof(long));
		sum=count=0;
                temp=n;
                root=ceil(sqrt(n));
		for(j=0;(n>1)&&(pr[j]<root);j++)
		{
                	freq=0;
			while(n%pr[j]==0)
			{
				freq++;
				n/=pr[j];
			}
			if(freq)
			{
				nfact[j]=pow(pr[j],freq);
				count++;
                        }
		}
                if(count==1&&n==1)sum=temp+1;
		if(n>1)
		{
			if(n==temp)sum=temp+1;
			else
			{
				nfact[j]=n;
				j++;

                        }
		}
		if(!sum)for(k=0;k<j;k++)sum+=nfact[k];
		if(temp==1)sum=2;
		printf("Case %ld: %lu\n",i,sum);
		i++;
                free(nfact);
        }
}













