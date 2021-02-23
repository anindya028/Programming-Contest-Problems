#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long long n;
        int cs=0;
	while(scanf("%lld",&n)==1&&n)printf("Case %d: %.0lf\n",++cs,ceil((3+sqrt(9+8*n))/2.0));
	return 0;
}













