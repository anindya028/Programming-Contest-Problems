//Adhoc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long long n;
	while(scanf("%lld",&n)==1&&n>0)
	{
        	if(n==1)printf("0%%\n");
		else printf("%lld%%\n",n*25);
	}
	return 0;
}













