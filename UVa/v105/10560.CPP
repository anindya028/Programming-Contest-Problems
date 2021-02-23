#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
unsigned long long w[42],sum[42];
int bisearch(unsigned long long key)
{
	int low=0,high=41,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(sum[mid]>=key)high=mid;
		else low=mid+1;
	}
	if(sum[low]>=key)return low;
	else return 0;
}
int main()
{
	long long n,k,s;
	long i,m;
        w[0]=sum[0]=1;
	for(i=1;i<42;i++)
	{
		w[i]=w[i-1]*3;
		sum[i]=sum[i-1]+w[i];
	}
	while(scanf("%lld%lld",&n,&k)==2)
	{
		if(!n&&!k)break;
		if(!n)printf("0\n");
		else
		{
			m=bisearch(n);
			printf("%ld",m+1);
			for(i=0;i<=m;i++)printf(" %llu",w[i]);
			printf("\n");
                }
		for(i=0;i<k;i++)
		{
			scanf("%lld",&s);
			if(!s)
			{
				printf("0\n");
				continue;
			}
			m=bisearch(s);
			printf("%llu",w[m]);
                        s-=w[m];
			while(s)
			{
				if(s>0)
				{	
					printf("+");
					m=bisearch(s);
					printf("%llu",w[m]);
					s-=w[m];
				}
				else
				{
					printf("-");            
					m=bisearch(s*(-1));
					printf("%llu",w[m]);
					s+=w[m];
				}
               		}
			printf("\n");
		}
	}
	return 0;
}













