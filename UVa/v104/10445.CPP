//Computational Geometry
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define myabs(a) ((a>0)?(a):-(a))
#define eps 1e-12
#define pye (2. * acos(0.0))
struct point
{
	double x,y;
}*p;
double triarea(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return 0.5*((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3));
}
bool right_turn(point a,point b,point c)
{
	if(triarea(a.x,a.y,b.x,b.y,c.x,c.y)>0.)
		return false;
	else return true;
}
double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double getangle(point a,point b,point c)
{
	double d1,d2,d3,theta;
	d1=dist(a,b);
	d2=dist(b,c);
	d3=dist(c,a);
	theta=acos((d1*d1+d2*d2-d3*d3)/(2*d1*d2));
	return ((180*theta)/pye);
}
int main()
{
	int n,i,flag;
	double ang,max,min,area;
	while(scanf("%d",&n)==1)
	{
		if(n<3)
			break;
		p=(point *)calloc(n,sizeof(point));
		min=36000;
		max=0;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		for(i=area=0;i<n;i++)
			area+=(p[i].x*p[(i+1)%n].y);
		for(i=0;i<n;i++)
			area-=(p[i].y*p[(i+1)%n].x);
		if(area<0)
			flag=0;
		else flag=1;
		for(i=0;i<n;i++)
		{
			ang=getangle(p[i],p[(i+1)%n],p[(i+2)%n]);
			if(right_turn(p[i],p[(i+1)%n],p[(i+2)%n]) && flag)
				ang=360-ang;
			if(!right_turn(p[i],p[(i+1)%n],p[(i+2)%n]) && !flag)
				ang=360-ang;
			if(ang>max)
				max=ang;
			if(ang<min)
				min=ang;
		}
		printf("%.6lf %.6lf\n",min,max);
		free(p);
	}
	return 0;
}













