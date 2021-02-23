//Geometry
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define pye (2.0*acos(0.0))
typedef unsigned long int myint;
void main()
{
	double s,q,arc,d;
	char p[3];
	while(scanf("%lf%lf%s",&s,&q,p)==3)
	{
		if(p[0]=='m')q=q/60.0;
		while(q>=360.0)q-=360.0;
                if(q>180)q=360.0-q;
		arc=(6440.0+s)*pye*q/180.0;
		d=(6440.0+s)*sqrt(2-2*cos(pye*q/180.0));
		printf("%.6lf %.6lf\n",arc,d);
	}
}













