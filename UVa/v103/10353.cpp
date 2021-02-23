#include<stdio.h>
#include<math.h>

#define sq(a) ((a)*(a))

int main()
{
	int t,i;
	double r,a1,a2,rt=sqrt(3.00);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&r);
		
		double lo=2*r,hi=4*r,mid;
		i=50;
		while(i--)
		{
			mid=(lo+hi)/2;
			if(2*mid > 2*r/rt + sqrt(4*sq(r)-sq(rt*mid/2-r)) + sqrt(4*sq(r)-sq(rt*mid/2 - 2*r)) + rt*r)
				hi=mid;
			else
				lo=mid;
		}
		a1=mid;
		
		lo=3.6*r,hi=3.8*r;
		i=50;
		while(i--)
		{
			mid=(lo+hi)/2;
			double x=rt*mid/2-r*(1.+rt),y=rt*mid/2-2*r;
			if(2*mid > 2*r/rt + rt*r + r + sqrt(4*sq(r)-sq(y)) + sqrt(4*sq(r) - sq(x)) )
				hi=mid;
			else
				lo=mid;
		}
		a2=mid;

		printf("%.12lf %.12lf\n",a1,a2);
	}
	return 0;
}