//Fibonacci
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,i,num;
	long long fib[52];
        fib[0]=1;
	fib[1]=2;
	fib[2]=3;
	for(i=3;i<=50;i++)fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		printf("Scenario #%d:\n%lld\n\n",i+1,fib[num]);
	}
	return 0;
}













