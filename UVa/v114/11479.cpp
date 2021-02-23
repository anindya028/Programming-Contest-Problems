#include<stdio.h>

#define Foro(i,a) for(i=0;i<(a);++i)

bool valid(long long a,long long b,long long c)
{
	return (a+b>c && a+c>b && b+c>a);
}


int main()
{
	long long t,cs,a,b,c;
	scanf("%lld",&t);
	Foro(cs,t)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if(!valid(a,b,c) || a<=0 || b<=0 || c<=0)
			printf("Case %lld: Invalid\n",cs+1);
		else if(a==b && b==c)
			printf("Case %lld: Equilateral\n",cs+1);
		else if(a==b || b==c || c==a)
			printf("Case %lld: Isosceles\n",cs+1);
		else
			printf("Case %lld: Scalene\n",cs+1);
	}
	return 0;
}