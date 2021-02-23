//Math
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long long n,k;
	double sum;
	while(scanf("%lld%lld",&n,&k)==2)
	{
        	sum=0.0;
		k=(n-k)<k?(n-k):k;
		for(;k;k--)sum+=(log10(n-k+1)-log10(k));
		printf("%.0lf\n",floor(sum)+1);
	}
	return 0;
}













