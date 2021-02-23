#include<stdio.h>
#include<math.h>

#define Max(a,b) (((a)>(b))?(a):(b))
//double
#define sq(a) ((a)*(a))
#define eps 1e-9
#define myabs(a) (((a)>0)?(a);-(a))
#define pye (2.*acos(0.0))
//double end

double m1,n1,m2,n2,m3,n3,R,area;

double calc2(double p)
{
	double b,c,a,s;
	a=(n1 + (m3*m1)/n3)*p;
	b=((m3*m1)/n3 + m1)*p;
	c=(m1 + n1)*p;
	s=(a+b+c)/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	return (area/s);
}

int main()
{
	int n,j;
	double res;
	double low,high,mid;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf",&R,&m1,&n1,&m2,&n2,&m3,&n3);
		low=eps*1000.;
		high=1000000;
		for(j=0;j<80;j++)
		{
			mid=(low+high)/2;
			res=calc2(mid);
			if(res<R)
				low=mid;
			else
				high=mid;
		}
		printf("%.4lf\n",area);
	}
	return 0;
}