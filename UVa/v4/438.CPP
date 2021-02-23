#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
void main()
{
	double x1,x2,x3,y1,y2,y3,a,b,c,x,y,r;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
	{
		a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
		c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
		x=(a+b+c)/2;
		 y=sqrt(x*(x-a)*(x-b)*(x-c));
                 r=a*b*c/(4.*y);
		printf("%.02lf\n",4*acos(0.)*r);
        }
}














