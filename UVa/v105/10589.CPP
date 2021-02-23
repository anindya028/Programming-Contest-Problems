#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define  eps 1e-12
bool check(double x,double y,double x0,double y0,double r)
{
	return ((x-x0)*(x-x0)+(y-y0)*(y-y0)+eps)<=r*r;
}
int main()
{
	int n,a,i,m;
	double x,y,ans;
	while(scanf("%d%d",&n,&a)==2)
	{
		if(!n && !a)break;
		for(i=m=0;i<n;i++)
		{
			scanf("%lf%lf",&x,&y);
			if(check(0,0,x,y,a)&&check(0,a,x,y,a)&&check(a,0,x,y,a)&&check(a,a,x,y,a))m++;
		}
		ans=(double)(m*a*a)/n;
		printf("%.5lf\n",ans);
	}
	return 0;
}













