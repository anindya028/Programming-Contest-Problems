#include<stdio.h>
#include<math.h>

#define S(a) ((a)*(a))
#define pye (2*acos(0.0))

double angle(double a,double b,double c)
{
	return acos((S(a)+S(b)-S(c))/(2*a*b));
}

double tria(double a,double b,double c)
{
	double s=(a+b+c)/2.;
	return (sqrt(s*(s-a))*sqrt((s-b)*(s-c)));
}

int main()
{
	int cs=0;
	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c)==3)
	{
		if(a<1 && b<1 && c<1)
			break;
		double s=(a+b+c)/2.0;
		double r=sqrt((s-a)*(s-b)*(s-c)/s);
		double ra=sqrt(s*(s-b)*(s-c)/(s-a));
		double rb=sqrt(s*(s-a)*(s-c)/(s-b));
		double rc=sqrt(s*(s-b)*(s-a)/(s-c));
		double ang_a=angle(b,c,a),ang_b=angle(c,a,b),ang_c=angle(a,b,c);
		double ang_a_ext=(pye-ang_a)/2,ang_b_ext=(pye-ang_b)/2,ang_c_ext=(pye-ang_c)/2;
		double ang_d=pye-ang_b_ext-ang_c_ext,ang_e=pye-ang_a_ext-ang_c_ext,ang_f=pye-ang_a_ext-ang_b_ext;
		double ans2 = ang_d*ra*ra/2 + ang_e*rb*rb/2 + ang_f*rc*rc/2;
		double ans1 = tria(a,b,c);
		double DB = sin(ang_c_ext)*a/sin(ang_d),
			DC = sin(ang_b_ext)*a/sin(ang_d); ans1+=tria(DB,DC,a);
		double EA = sin(ang_c_ext)*b/sin(ang_e),
			EC = sin(ang_a_ext)*b/sin(ang_e); ans1+=tria(EA,EC,b);
		double FA = sin(ang_b_ext)*c/sin(ang_f),
			FB = sin(ang_a_ext)*c/sin(ang_f); ans1+=tria(FA,FB,c);
		printf("Case %d: %.2lf %.2lf\n",++cs,ans1,ans2);
	}
	return 0;
}