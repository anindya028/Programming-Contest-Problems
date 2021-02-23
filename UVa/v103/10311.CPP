#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 100000050
unsigned long prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
long pr[5761470];
unsigned long sieve()
{
    memset( prime, -1, sizeof( prime ) );
    unsigned long i,i2,j;
    unsigned long sqrtN = ( unsigned long )sqrt( ( double )N ) + 1;
    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
    {
        i2 = i + i;
        for( j = i * i; j < N; j += i2 ) rP( j );
    }
	j=1;
	pr[0]=2;
	for(i=3;i<(N-50);i+=2)
	{
		if(gP(i))
		{
			pr[j]=i;
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
void main()
{
	long m=sieve();
	long n,temp,half,flag;
	while(scanf("%ld",&n)==1)
	{	
		flag=0;
		if(n%2)
		{
			if(bisearch(n-2,m))printf("%ld is the sum of 2 and %ld.\n",n,n-2);
			else printf("%ld is not the sum of two primes!\n",n);
		}
		else
		{
			temp=n/2;
			if(temp%2)
			{
				half=bisearch1(temp,m);
					for(half--;half>0;half--)
					{
						if(bisearch(n-pr[half],m))
						{
							printf("%ld is the sum of %ld and %ld.\n",n,pr[half],n-pr[half]);
							flag=1;
							break;
						}
					}
					if(!flag)printf("%ld is not the sum of two primes!\n",n);
			}
			else
			{
				half=bisearch1(temp,m);
				for(half--;half>0;half--)
				{
					if(bisearch(n-pr[half],m))
					{
						printf("%ld is the sum of %ld and %ld.\n",n,pr[half],n-pr[half]);
						flag=1;
						break;
					}
				}
				if(!flag)printf("%ld is not the sum of two primes!\n",n);
			}
		}
        }
}













