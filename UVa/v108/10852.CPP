#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define size 3000
long pr[1200];
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
long bisearch(long key,long m)
{
	long low=0,high=m-1,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(pr[mid]>key)high=mid;
		else low=mid+1;
	}
	if(pr[low]>key)return low;
	else return 0;
}
int main()
{
	long m=gene(size*2);
	long ar[10001],i,n,q;
	for(i=5;i<10001;i++)
	{
		ar[i]=pr[bisearch(i/2,m)];
	}
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&q);
		printf("%ld\n",ar[q]);
	}
	return 0;
}













