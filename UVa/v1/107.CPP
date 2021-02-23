#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64
#define Long long long
int main()
{
	int a,b,n,k,i;
	Long N,sum;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a && !b)
			break;
		if(a==1 && b==1)
		{
			printf("0 1\n");
			continue;
		}
		for(i=1;i<31;i++)
		{
			n=(int)pow((double)b,1./i);
			if(pow(n,i)==(double)b)
			{
				if(pow(n+1,i)==(double)a)
				{
					k=i;
					break;
				}
			}
			n++;
			if(pow(n,i)==(double)b)
			{
				if(pow(n+1,i)==(double)a)
				{
					k=i;
					break;
				}
			}
		}
		sum=N=0;
		for(i=0;i<k;i++)
			N+=(int)pow(n,i);
		for(i=0;i<=k;i++)
		{
			sum+=(int)pow(n+1,i)*b;
			b/=n;
		}
		printf("%lld %lld\n",N,sum);
	}
	return 0;
}













