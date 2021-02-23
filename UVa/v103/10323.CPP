//Adhoc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long long ans;
	long n,i;
	while(scanf("%ld",&n)==1)
	{
		if(n<0)
		{
			if(abs(n)%2)printf("Overflow!\n");
			else printf("Underflow!\n");
			continue;
		}
		if(n<8)printf("Underflow!\n");
		else if(n>13)printf("Overflow!\n");
		else
		{
			ans=1;
			for(i=2;i<=n;i++)ans*=(long long)i;
			printf("%lld\n",ans);
		}
	}
	return 0;
}













