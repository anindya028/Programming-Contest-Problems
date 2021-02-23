#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,i;
        double r1,r2,r3,a,b,c,A,B,C,s,area;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf",&r1,&r2,&r3);
		a=r1+r2;
		b=r1+r3;
		c=r2+r3;
		s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		A=acos((b*b+c*c-a*a)/(2*b*c));
		B=acos((-b*b+c*c+a*a)/(2*a*c));
		C=acos((b*b-c*c+a*a)/(2*b*a));
		area-=(A*r3*r3/2.0);
		area-=(B*r2*r2/2.0);
		area-=(C*r1*r1/2.0);
		printf("%.6lf\n",area);
	}
	return 0;
}













