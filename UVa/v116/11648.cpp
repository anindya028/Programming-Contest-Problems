#include<stdio.h>
#include<math.h>

int main()
{
	int t,cs;
	double AB,CD,AD,BC;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%lf%lf%lf%lf",&AB,&CD,&AD,&BC);
		double a=AB-CD,b=AD,c=BC,s=(a+b+c)/2;
		double h=(sqrt(s*(s-a))*sqrt((s-b)*(s-c)))/(.5*a);
		double lo=0,hi=h,mid;
		int i=600;
		while(i--)
		{
			mid=(lo+hi)/2;
			double a1=(mid*a)/h;
			if(mid*(2*CD+a1)<(h-mid)*(AB+CD+a1))
				lo=mid;
			else
				hi=mid;
		}
		mid=h-lo;
		printf("Land #%d: %.6lf %.6lf\n",cs+1,(mid*AD)/h,(mid*BC)/h);
	}
	return 0;
}