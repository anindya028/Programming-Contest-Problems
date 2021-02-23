#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 5000000
//#define Long __int64
//#define Long long long
long pr[664579];
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
long bisearch1(long key,long n)
{
	long low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(pr[mid]>=key)high=mid;
		else low=mid+1;
	}
	if(pr[low]>=key)return low;
	else return 0;
}
int main()
{
	long m=gene(size*2);
        long n,i,half;
	while(scanf("%ld",&n)==1)
	{
		if(n<8)
		{
			printf("Impossible.\n");
			continue;
                }
		if(n%2)
		{
			n-=5;
			printf("2 3 ");
                }
		else
		{
			n-=4;
			printf("2 2 ");
		}
		half=n/2;
		if(bisearch(half,m))
		{
			printf("%ld %ld\n",half,half);
			continue;
		}
        else i=bisearch1(half,m);
		for(;i>=0;i--)
		{
			if(bisearch(n-pr[i],m))
			{
				printf("%ld %ld\n",pr[i],n-pr[i]);
				break;
			}
		}
        }
	return 0;
}













