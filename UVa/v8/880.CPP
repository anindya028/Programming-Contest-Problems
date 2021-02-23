#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	long long  t,n,a,b,c;
	while(scanf("%lld",&t)==1)
	{
		n=(long long)floor((-1+sqrt(1.+8.*t))/2.);
		if((n*(n+1)/2)>=t)
			n--;
		if(n%2==0)
		{
			c=n*(n+1)/2;
			a=(n+1)-(t-c-1);
			b=n+2-a;
			printf("%lld/%lld\n",a,b);
		}
		else
		{
			c=c=n*(n+1)/2;
			a=t-c;
			b=n+2-a;
			printf("%lld/%lld\n",b,a);
		}
	}
	return 0;
}













