#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,sum[45000],i,j,k;
	long long n;
	sum[0]=0;
	for(i=1;i<44999;i++)
		sum[i]=sum[i-1]+i;
	while(scanf("%lld",&n)==1)
	{
		if(n<0)break;
		if(!n)
		{
			printf("0 = 0 + ... + 0\n");
			continue;
		}
		k=(int)((-1+sqrt((double)(1+8*n)))/2.0)+1;
		for(j=k;j;j--)
		{
			if(sum[j]>n)continue;
			if((n-sum[j])%j==0)
			{
				a=1+(n-sum[j])/j;
				b=a+j-1;
				break;
			}
		}
		printf("%lld = %d + ... + %d\n",n,a,b);
	}
	return 0;
}