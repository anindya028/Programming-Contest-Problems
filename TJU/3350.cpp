#include<stdio.h>

struct point 
{
	double x,y;
}p[10005];

int main()
{
	int n,i;
	double a;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		a=0.;
		for(i=0;i<n;i++)
			a+=(p[i].x*p[(i+1)%n].y);
		for(i=0;i<n;i++)
			a-=(p[i].y*p[(i+1)%n].x);
		if(a<0)
			a*=-1;
		printf("%.0lf\n",a/2.+1e-5);
	}
	return 0;
}