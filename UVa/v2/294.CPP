#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 32000
struct prime
{
	unsigned m:1;
};
long pr[5000];
prime p[size/2];
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
	int n,*fact,num=gene(size),root,i;
        scanf("%d",&n);
	long p,d,l,u,j,temp,factor,k;
	for(i=0;i<n;i++)
	{
                p=d=0;
		scanf("%ld%ld",&l,&u);
		for(j=l;j<=u;j++)
		{
			root=ceil(sqrt(j));
			fact=(int *)calloc(num,sizeof(int));
			temp=j;
                        factor=1;
			for(k=0;k<num&&temp>1;k++)
			{
                        	if(pr[k]>root)break;
				while(temp%pr[k]==0)
				{
					fact[k]++;
					temp/=pr[k];
				}
				if(fact[k])
				{
					factor*=(fact[k]+1);
					root=ceil(sqrt(temp));
				}
			}
                        if(temp!=1)factor*=2;
			if(factor>d)
			{
				p=j;
				d=factor;
			}
			free(fact);
		}
		printf("Between %ld and %ld, %ld has a maximum of %ld divisors.\n",l,u,p,d);
        }
}













