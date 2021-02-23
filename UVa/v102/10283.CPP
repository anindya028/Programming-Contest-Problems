//Euclidean Geometry
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define pi 2*acos(0.0)
int main()
{
	double R,n,r,I,E,q,c,a;
	while(scanf("%lf%lf",&R,&n)==2)
	{
		if(n==1)
		{
			r=R;
			E=I=0;
			printf("%.10lf %.10lf %.10lf\n",r,I,E);
			continue;
		}
		if(n==2)
		{
			r=R/2;
			I=0;
			E=pi*(R*R-2*r*r);
			printf("%.10lf %.10lf %.10lf\n",r,I,E);
			continue;
		}
		q=2*pi/n;
		c=(1.0+cos(q))/(1.0-cos(q));
		r=R*(sqrt(1+c)-1)/c;
		a=2*r*cos(q/2)/sin(q);
		E=(q*R*R/2-r*sqrt(a*a-r*r)-(pi+q)*r*r/2)*n;
		I=pi*R*R-E-pi*r*r*n;
		printf("%.10lf %.10lf %.10lf\n",r,I,E);
        }	
	return 0;
}













