#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 500000
long pr[80000];
bool p[size];
long gene(long n)
{
	int root=ceil(sqrt(n));
        long i,j;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2]=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i])
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
int main()
{
	long m=gene(size*2);
	long n,i;
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		printf("%ld:\n",n);
		if(n%2)
		{
			if(bisearch(n-2,m))printf("2+%ld\n",n-2);
			else printf("NO WAY!\n");
		}
		else
		{
			for(i=0;;i++)
			{
				if(bisearch(n-pr[i],m))
				{
					printf("%ld+%ld\n",pr[i],n-pr[i]);
					break;
				}
			}
		}
	}
	return 0;
}













