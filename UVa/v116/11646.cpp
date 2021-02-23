#include<stdio.h>
#include<math.h>

int main()
{
	double a,b,x;
	int cs=0;
	while(scanf("%lf : %lf",&a,&b)==2)
		x=400/(2*a+2*sqrt(a*a+b*b)*atan(b/a)),
		printf("Case %d: %.10lf %.10lf\n",++cs,a*x,b*x);
	return 0;
}