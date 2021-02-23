#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
long long count,high,a;
void func(long long n)
{
	if(n==1)return;
	if(n%2 && (3*n+1)>high)return;
	count++;
	if(n%2==0)func(n/2);
	else func(3*n+1);
}
int main()
{
	int cs=0;
	while(scanf("%lld%lld",&a,&high)==2 && a>0)
	{
		count=1;
		func(a);
		printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",++cs,a,high,count);
	}
	return 0;
}













