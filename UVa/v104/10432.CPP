//Easy Geometry
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define pye 2*acos(0.0)
int main()
{
	double q,n,r,a,s;
	while(scanf("%lf%lf",&r,&n)==2)
	{
		q=2*pye/n;
		a=sqrt(2*r*r*(1-cos(q)));
		s=(a+2*r)/2.0;
		printf("%.3lf\n",n*(s-r)*sqrt(s*(s-a)));
	}
	return 0;
}













