//Geo Easy
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define pye 2*acos(0.0)
int main()
{
	double a,b,c,area,s,r,R,yellow,violet,red;
	while(scanf("%lf%lf%lf",&a,&b,&c)==3)
	{
		s=(a+b+c)/2.0;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		r=area/s;
		R=a*b*c/(4*area);
		red=pye*r*r;
		violet=area-red;
		yellow=pye*R*R-area;
		printf("%.4lf %.4lf %.4lf\n",yellow,violet,red);
	}
	return 0;
}













