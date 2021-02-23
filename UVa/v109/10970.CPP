#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
long min(long m,long n)
{
	return m<n?m:n;
}
long max(long m,long n)
{
	return m>n?m:n;
}
int main()
{
	long m,n;
	while(scanf("%ld%ld",&m,&n)==2)printf("%ld\n",min(m,n)-1+min(m,n)*(max(m,n)-1));
	return 0;
}













