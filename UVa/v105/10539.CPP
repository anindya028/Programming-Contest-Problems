#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 1000000
struct prime
{
	unsigned m:1;
};
long pr[78498],m;
prime p[500000];
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
long almost(long long n)
{
	long root=ceil(sqrt(n));
	long i,count=0;
	double a,b,c;
	for(i=0;i<m;i++)
	{
		if(pr[i]>root)break;
		a=log10(n);
		b=log10(pr[i]);
		c=a/b;
		count+=(floor(c)-1);
	}
	return count;
}
int main()
{
	long i,n,countl,counth;
        long long low,high;
        m=gene(size);
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&low,&high);
		countl=counth=0;
		if(low>4)countl=almost(low-1);
		if(high>3)counth=almost(high);
                printf("%ld\n",counth-countl);
        }
	return 0;
}













