#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

#define S(a) ((a)*(a))

struct point
{
	double x,y;
	double ang;
}u;

vector<point> vp;

double dist(point a,point b)
{
	return sqrt(S(a.x-b.x)+S(a.y-b.y));
}

double calc(point a,point b,point c)
{
	double ab=dist(a,b),bc=dist(b,c),ca=dist(c,a);
	return acos((S(ab)+S(bc)-S(ca))/(2*ab*bc));
}

int main()
{
	int n,i;
	double d;
	while(scanf("%lf%d",&d,&n)==2 && n)
	{
		if(n<3)
		{
			printf("%.3lf\n",0.0);
			continue;
		}
		vp.clear();
		for(i=0;i<n;i++)
			scanf("%lf%lf",&u.x,&u.y),vp.push_back(u);
		for(i=0;i<n;i++)
			vp[i].ang=calc(vp[(i-1+n)%n],vp[i],vp[(i+1)%n]);
		double area=0;
		for(i=0;i<n;i++)
			area+=vp[i].x*vp[(i+1)%n].y;
		for(i=0;i<n;i++)
			area-=vp[i].y*vp[(i+1)%n].x;
		area*=.5;
		if(area<0)
			area*=-1.;
		double sum=0;
		for(i=0;i<n;i++)
		{
			double a= dist(vp[i],vp[(i+1)%n]);
			double b= a - d/tan(.5*vp[i].ang) - d/tan(.5*vp[(i+1)%n].ang);
			sum+=(.5*d*(a+b));
		}
		printf("%.3lf\n",area-sum);
	}
	return 0;
}