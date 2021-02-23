#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
void main()
{
	double a,b,c,s,r;
	while(scanf("%lf%lf%lf",&a,&b,&c)==3)
	{
		s=(a+b+c)/2.0;
		if(s)r=sqrt(s*(s-a)*(s-b)*(s-c))/s;
		else r=0;
		printf("The radius of the round table is: %.03lf\n",r);
	}
}













