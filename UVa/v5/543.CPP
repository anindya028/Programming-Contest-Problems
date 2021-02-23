#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 1000000
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[78498];
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
long bisearch(long key,long n)
{
	long low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(pr[mid]==key)return pr[mid];
		else if(pr[mid]>key)high=mid-1;
		else low=mid+1;
	}
	return 0;
}
void main()
{
	long num=gene(size);
	long i,n,k;
	for(i=0;;i++)
	{
		scanf("%ld",&n);
		if(!n)break;
		for(k=1;k<num;k++)
                {
			if(bisearch(n-pr[k],num))
			{
				printf("%ld = %ld + %ld\n",n,pr[k],n-pr[k]);
				break;
			}
		}
        }
}













