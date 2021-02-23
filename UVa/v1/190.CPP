#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define eps 1e-12
int main()
{
	double x1,y1,x2,y2,x3,y3,h,k,r,c,d,e,D,c1,c2;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
	{
		D=(x1-x2)*(y2-y3)-(y1-y2)*(x2-x3);
		c1=(x1*x1+y1*y1-x2*x2-y2*y2)/2.0;
		c2=(x2*x2+y2*y2-x3*x3-y3*y3)/2.0;
		h=(c1*(y2-y3)-c2*(y1-y2))/D;
		k=(-c1*(x2-x3)+c2*(x1-x2))/D;
		r=sqrt((h-x1)*(h-x1)+(k-y1)*(k-y1));
		printf("(x ");
		if(-h+eps>0)printf("+ %.3lf)^2 + (y ",fabs(h));
		else printf("- %.3lf)^2 + (y ",fabs(h));
		if(-k+eps>0)printf("+ %.3lf)^2 = %.3lf^2\n",fabs(k),r);
		else printf("- %.3lf)^2 = %.3lf^2\n",fabs(k),r);
		c=-2*h;
		d=-2*k;
		e=h*h+k*k-r*r;
		printf("x^2 + y^2 ");
		if(c+eps>0)printf("+ %.3lfx ",c);
		else printf("- %.3lfx ",fabs(c));
		if(d+eps>0)printf("+ %.3lfy ",d);
		else printf("- %.3lfy ",fabs(d));
		if(e+eps>0)printf("+ %.3lf = 0\n",e);
		else printf("- %.3lf = 0\n",fabs(e));
		printf("\n");
	}
	return 0;
}













