#include<stdio.h>

#define LL long long

int main()
{
	int t;
	LL n,lo,mid,hi;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		lo=0,hi=1000000000;
		while(lo<hi)
		{
			mid=(lo+hi+1)/2;
			if((mid*(mid+1))/2<=n)
				lo=mid;
			else
				hi=mid-1;
		}
		printf("%lld\n",lo);
	}
	return 0;
}