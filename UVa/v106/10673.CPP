#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	long t,x,k,i;
        scanf("%ld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%ld %ld",&x,&k);
		printf("%ld %ld\n",k-(x%k),x%k);
        }
	return 0;
}













