#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define eps 1e-9
#define inf 100000000.
#define myabs(a) (((a)>0)?(a):-(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define tria(p,q,r) myabs(triarea(p.x,p.y,q.x,q.y,r.x,r.y))

struct point 
{
	double x,y;
};

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

bool interdivide(point a,point b,point c)
{
	if((c.x>a.x && c.x<b.x) || (c.x<a.x && c.x>b.x) || (c.y>a.y && c.y<b.y) || (c.y<a.y && c.y>b.y))
		return true;
	return false;
}

bool samepoint(point a,point b)
{
	if(myabs(a.x-b.x)<eps && myabs(a.y-b.y)<eps)
		return true;
	return false;
}

bool lineseg_lineseg(point a,point b,point c,point d)//checks whether AB & CD intersects or not
{
	double m1,m2;
	if(myabs(b.x-a.x)<eps)m1=inf;
	else m1=(b.y-a.y)/(b.x-a.x);
	if(myabs(d.x-c.x)<eps)m2=inf;
	else m2=(d.y-c.y)/(d.x-c.x);
	if(myabs(m1-m2)<eps)
	{
		if(myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))>eps)
			return false;
		if(samepoint(a,c) || samepoint(a,d) || samepoint(b,c) || samepoint(b,d))
			return true;
		if(interdivide(a,b,c) || interdivide(a,b,d) || interdivide(c,d,a) || interdivide(c,d,b))
			return true;
		else return false;
	}
	else
	{
		if((right_turn(a,b,c) ^ right_turn(a,b,d)) && (right_turn(c,d,a) ^ right_turn(c,d,b)))
			return true;
		return false;
	}
}

bool fully_inter(point p,point q,point a,point b,point c,point d)
{
	double first=tria(p,a,b)+tria(p,b,c)+tria(p,c,d)+tria(p,d,a);
	double second=tria(q,a,b)+tria(q,b,c)+tria(q,c,d)+tria(q,d,a);
	return myabs(first-second)<eps;
}

int main()
{
	point p,q,a,b,c,d;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p.x,&p.y,&q.x,&q.y,&a.x,&a.y,&c.x,&c.y);
		b.x=a.x;
		b.y=c.y;
		d.x=c.x;
		d.y=a.y;
		if(lineseg_lineseg(p,q,a,b) || lineseg_lineseg(p,q,b,c) || lineseg_lineseg(p,q,c,d) || lineseg_lineseg(p,q,d,a) || fully_inter(p,q,a,b,c,d))
			printf("T\n");
		else printf("F\n");
	}
	return 0;
}













