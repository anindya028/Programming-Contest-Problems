#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long long s,d,n,m;
	long double r;
	while(scanf("%lld%lld",&s,&d)==2)
	{
		r=sqrtl((2*s-1)*(2*s-1)+8*d);
		n=(long)floor((1-2*s+r)/2.0+1e-12);
		m=(long)ceil((1-2*s+r)/2.0+1e-12);
		if((n*s+n*(n-1)/2)>=d)printf("%lld\n",n+s-1);
		else printf("%lld\n",m+s-1);
	}
	return 0;
}













