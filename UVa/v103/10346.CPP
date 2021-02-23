#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long long n,k,ans;
	while(scanf("%lld%lld",&n,&k)==2)
	{
		ans=n;
		while(n>=k)
		{
			ans+=(long long)(n/k);
			n=n/k+n%k;
		}
		printf("%lld\n",ans);
	}
	return 0;
}













