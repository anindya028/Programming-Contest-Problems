 #include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a>b)?(a):(b))
int main()
{
	int i,n;
	double a,b,c,d1,d2,d3,ha,hb,hc,area,s;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		s=(a+b+c)/2.;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		ha=area*2/a;
		hb=area*2/b;
		hc=area*2/c;
		if((b*b+c*c+eps)<=a*a)
		{
			d1=b*hb/(hb+sqrt(a*a-hb*hb));
			d2=c*hc/(hc+sqrt(a*a-hc*hc));
			d3=a*ha/(a+ha);
		}
		else if((a*a+c*c+eps)<=b*b)
		{
			d1=a*ha/(ha+sqrt(b*b-ha*ha));
			d2=c*hc/(hc+sqrt(b*b-hc*hc));
			d3=hb*b/(b+hb);
		}
		else if((a*a+b*b+eps)<=c*c)
		{
			d1=a*ha/(ha+sqrt(c*c-ha*ha));
			d2=b*hb/(hb+sqrt(c*c-hb*hb));
			d3=hc*c/(c+hc);
		}
		else 
		{
			d1=ha*a/(a+ha);
			d2=hb*b/(b+hb);
			d3=hc*c/(c+hc);
		}
		s=max(d1,max(d2,d3));
		printf("%.6lf\n",s*s);
	}
	return 0;
}













