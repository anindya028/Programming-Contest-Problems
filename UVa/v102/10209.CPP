//Euclidean geometry
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
#define pi (2.*acos(0))
void main()
{
	double a;
	while(scanf("%lf",&a)==1)
	{
		double x,y,z;
		x=a*a*(pi/3-sqrt(3.)+1.);
		y=a*a*(pi-2.)-2.*x;
		z=a*a-x-y;
		printf("%.3lf %.3lf %.3lf\n",x,y,z);
        }
}













