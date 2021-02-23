#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 25000
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[5200],num;
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
int divide(long n,long m)
{
	long root=ceil(sqrt(m)),temp,i=0,j;
	int *factn,*factm;
	factn=(int *)calloc(num,sizeof(int));
	factm=(int *)calloc(num,sizeof(int));
	for(;i<num&&m>1;i++)
	{
		if(pr[i]>root)break;
		while(m%pr[i]==0)
		{
			factm[i]++;
			m/=pr[i];
		}
	}
	if(m!=1)
	{
		if(m>n)
		{
			free(factn);
		       	free(factm);
			return 0;
		}
        }
	for(j=0;j<i;j++)
	{
		temp=n;
		while(temp)
		{
			factn[j]+=temp/=pr[j];
		}
		if(factm[j]>factn[j])
		{
			free(factn);
			free(factm);
			return 0;
		}
	}
	free(factn);
	free(factm);
        return 1;
}		
void main()
{
	num=gene(size*2);
	long n,m;
	while(scanf("%ld%ld",&n,&m)==2)
	{
		if(!m)printf("%ld does not divide %ld!\n",m,n);
		else if(m<=n)printf("%ld divides %ld!\n",m,n);
		else
		{
			if(divide(n,m))printf("%ld divides %ld!\n",m,n);
			else printf("%ld does not divide %ld!\n",m,n);
		}
	}
}














