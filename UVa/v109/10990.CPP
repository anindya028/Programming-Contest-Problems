#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 2000000
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[239],m;
prime p[750];
long phi[size+1];
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
long gener(long n)
{
	long root=ceil(sqrt(n));
	long j,power;
	double p=n;
	long temp=n;
	for(j=0;(n>1)&&(j<m);j++)
	{
               	if(pr[j]>root)break;
		power=0;
		while(n%pr[j]==0)
		{
			power++;
			if(power>1)
			{
				p=phi[(temp/pr[j])]*pr[j];
				return (long)p;
                        }
			n/=pr[j];
		}
		if(power)
		{
			p*=(pr[j]-1);
			p/=pr[j];
			root=ceil(sqrt(n));
		}
	}
	if(n>1)
	{
		p*=(n-1);
		p/=n;
	}
        return (long)p;
}
void main()
{
	m=gene(1500);
	long i=3,*depth,*sod,low,high;
	depth=(long *)calloc((size+1),sizeof(long));
	sod=(long *)calloc((size+1),sizeof(long));
	phi[2]=depth[2]=sod[2]=1;
	for(;i<=size;i++)
	{
		phi[i]=gener(i);
		depth[i]=depth[phi[i]]+1;
		sod[i]=sod[i-1]+depth[i];
	}
	int n;
        scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%ld%ld",&low,&high);
		printf("%ld\n",sod[high]-sod[low-1]);
	}
	free(depth);
	free(sod);
}













