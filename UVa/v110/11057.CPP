#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
long *price;
int comp(const void *a, const void *b) {
    long *x=(long *)a; 
    long *y=(long *)b; 
    if(*x>*y) return 1; 
    if(*x<*y) return -1; 
    else return 0; 
}
long bisearch(long key,long n)
{
	long low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(price[mid]==key)return price[mid];
		else if(price[mid]>key)high=mid-1;
		else low=mid+1;
	}
	return 0;
}
long bisearch1(long key,long n)
{
	long low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(price[mid]<key)low=mid;
		else high=mid-1;
	}
	if(price[low]<key)return low;
	else return 0;
}
int main()
{
	long n,sum,i,count;
	while(scanf("%ld",&n)==1)
	{
		price=(long *)calloc(n,sizeof(long));
		for(i=0;i<n;i++)
			scanf("%ld",&price[i]);
		scanf("%ld",&sum);
		qsort(price,n,sizeof(price[0]),comp);
		if(sum%2==0)
			for(i=count=0;i<n;i++)
				if(price[i]==sum)
				{
					count++;
					if(count==2)break;
                                }
		if(count==2)
		{
			printf("Peter should buy books whose prices are %ld and %ld.\n\n",sum/2,sum/2);
			continue;
                }
		for(i=bisearch1(sum/2,n);i>=0;i--)
			if(bisearch(sum-price[i],n))
			{
				printf("Peter should buy books whose prices are %ld and %ld.\n\n",price[i],sum-price[i]);
				break;
			}
		free(price);
	}
	return 0;
}













