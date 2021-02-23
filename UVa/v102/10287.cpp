#include<stdio.h>
#include<math.h>

#define eps 1e-9
#define pye (2.*acos(0.0))
#define sq(a) ((a)*(a))

int main()
{
	double r1,r2,r3,r4,a;
	int i;
	while(scanf("%lf",&a)==1)
	{
		r1=a/(2*tan(pye/6));
		r2=a/(2/sqrt(3.0) +1);
		r3=a*sqrt(3.0)/4.;
		double lo=1e-11,hi=1e8,mid;
		i=100;
		while(i--)
		{
			mid=(lo+hi)/2;
			double res=mid/cos(pye/6) + sqrt(4*mid*mid - sq(a*sqrt(3.0)/2. - mid));
			if(res>a)
				hi=mid;
			else
				lo=mid;
		}
		r4=mid;
		printf("%.10lf %.10lf %.10lf %.10lf\n",r1,r2,r3,r4);
	}
	return 0;
}