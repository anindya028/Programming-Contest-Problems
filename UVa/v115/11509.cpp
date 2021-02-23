#include<stdio.h>
#include<math.h>

#define sq(a) ((a)*(a))
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,(a))
//double begin
#define eps 1e-9
#define myabs(a) ((a)>0?(a):-(a))
#define pye 2*acos(0.0)

bool equal(double a,double b)
{
	return myabs(a-b)<eps;
}
//double end
struct point
{
	double x,y;
}p[1005];

double triarea(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return 0.5*((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3));
}

bool right_turn(point a,point b,point c)
{
	if(triarea(a.x,a.y,b.x,b.y,c.x,c.y)>0.)
		return false;
	return true;
}

bool on_line(point a,point b,point c)
{
	if(myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))<eps)
		return true;
	return false;
}

double dist(point a,point b)
{
	return sqrt(sq(a.x-b.x)+sq(a.y-b.y));
}

double calc(point a,point b,point c)
{
	double ab=dist(a,b),bc=dist(b,c),ac=dist(a,c);
	double ang=pye-acos((sq(ab)+sq(bc)-sq(ac))/(2*ab*bc));
	if(on_line(a,b,c))
	{
		if(equal(ac,(ab+bc)))
			return 0.0;
		else
			return pye;
	}
	if(!right_turn(a,b,c))
		return ang;
	else
		return (2*pye-ang);
}

int main()
{
	int n,i;
	double sum;
	while(scanf("%d",&n)==1 && n)
	{
		Foro(i,n)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		sum=0.;
		For(i,1,n)
			sum+=calc(p[i-1],p[i],p[(i+1)%n]);
		printf("%.0lf\n",ceil(sum/(2*pye)-eps));
	}
	return 0;
}