#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define eps 1e-12
double out_put(double d)
{
	return (floor(d*10+.5)/10.0);
}
int main()
{
	double d,m,a,j,jta,jts,jtd,jt,at,A,b,c,r,dist;
	while(scanf("%lf%lf%lf%lf",&d,&m,&a,&j)==4)
	{
		//a=fabs(a);
		jta=a/j;
		jts=sqrt(m/j);
		jtd=exp(log(d/(2*j))/3);
		jt=jta;
		if((jts+eps)<jt)jt=jts;
		if((jtd+eps)<jt)jt=jtd;
		at=(m-j*pow(jt,2))/a;
		A=.5*a;
		b=a*jt+0.5*j*pow(jt,2);
		c=j*(jt*jt*jt)-d/2;
		r=(-b+sqrt(b*b-4*A*c))/(2*A);
		if((r+eps)<at)at=r;
		dist=j*pow(jt,3)+0.5*j*pow(jt,2)*at+.5*a*pow(at,2)+a*(at*jt);
		printf("%.1lf\n",out_put(4*jt+2*at+2*(d/2-dist)/m));
	}
	return 0;
}













