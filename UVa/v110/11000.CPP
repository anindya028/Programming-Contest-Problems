//Good Linear DP
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
#define Long long long
struct bee
{
	Long m,f;
}b[100];
int main()
{
	Long lim=(Long)pow(2,32);
	Long fib[100];
	b[0].m=0;
	b[0].f=1;
	b[1].m=1;
	b[1].f=1;
	fib[0]=1;
	fib[1]=1;
	int i,n;
	for(i=2;(b[i-1].m+b[i-1].f)<=lim;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		b[i].m=b[i-1].m+fib[i-1];
		b[i].f=b[i-1].f+fib[i-2];
	}
	while(scanf("%d",&n)==1)
	{
		if(n==-1)break;
		printf("%lld %lld\n",b[n].m,b[n].m+b[n].f);
	}
	return 0;
}













