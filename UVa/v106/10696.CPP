#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
/*long f91(long n)
{
	if (n<=100)return f91(n+11);
	else return n-10;
}*/
int main()
{
	long n;
	while(scanf("%ld",&n)==1&&n)
	{
		if(n<0)continue;
		if(n<=100)printf("f91(%ld) = 91\n",n);
		else printf("f91(%ld) = %ld\n",n,n-10);
	}
	return 0;
}













