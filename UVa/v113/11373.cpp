#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

#define inf 1e12
#define eps 1e-9
#define mabs(a) (((a)>0)?(a):-(a))
#define E(a,b) (mabs(a-b)<eps)
#define Z(a) E(a,0)
#define sq(a) ((a)*(a))
#define pye (2*acos(0.0))
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))

struct point
{
	double x,y;
	point(){x=0,y=0;}
	point(double x0,double y0){x=x0,y=y0;}
}I;

inline double dist(point a,point b)
{
	return hypot(a.x-b.x,a.y-b.y);
}

double angle_bac(point B,point A,point C)
{
	double c=dist(A,B),b=dist(A,C),a=dist(B,C);
	return acos((sq(c)+sq(b)-sq(a))/(2*b*c));
}

struct line
{
	double m,c;		//y=mx+c.
	line(){m=1,c=0;}
	line(double m0,double c0){m=m0,c=c0;};
};

line pts2line(point a,point b)
{
	line ret;
	if(E(a.x,b.x))
		ret.m=inf,
		ret.c=-a.x;
	else
		ret.m=(b.y-a.y)/(b.x-a.x),
		ret.c=a.y-ret.m*a.x;
	return ret;
}

struct circle
{
	double cx,cy,rad;	//(x-cx)^2 + (y-cy)^2 = rad^2.
}britto;

vector<point> circle_line(circle O,line l)	//l->y=mx+c
{
	vector<point> ret;
	point p1,p2;
	
	if(E(l.m,inf))		//given line is x+c=0.
	{
		if(E(sq(O.rad),sq(O.cx+l.c)))	//touch
			p1.y=O.cy,p1.x=-l.c,
			ret.push_back(p1);
		else if(sq(O.cx+l.c) < sq(O.rad))	//intersect
		{
			p1.y=O.cy+sqrt(sq(O.rad)-sq(O.cx+l.c));
			p2.y=O.cy-sqrt(sq(O.rad)-sq(O.cx+l.c));
			p1.x=p2.x=-l.c;
			ret.push_back(p1),ret.push_back(p2);
		}
		return ret;
	}
	
	double c1=l.c-O.cy,
		A=1+sq(l.m),
		B=2*l.m*c1-2*O.cx,
		C=sq(O.cx)+sq(c1)-sq(O.rad),
		D=sq(B)-4*A*C;
	
	if(Z(D))			//touch
		p1.x=-B/(2*A),
		p1.y=l.m*p1.x+l.c,
		ret.push_back(p1);
	else if(D>0)		//intersect			
		p1.x=(-B+sqrt(D))/(2*A),
		p1.y=p1.x*l.m+l.c,
		p2.x=(-B-sqrt(D))/(2*A),
		p2.y=p2.x*l.m+l.c,
		ret.push_back(p1),
		ret.push_back(p2);
	
	return ret;
}

inline double dotProduct(point a,point b)
{
	return a.x*b.x+a.y*b.y;
}

point intersect(point a,point b,point c,point d) //AB & CD not parallel
{
	double denom,num,t;
	point n(d.y-c.y,c.x-d.x),ba(b.x-a.x,b.y-a.y),ac(a.x-c.x,a.y-c.y);
	denom=dotProduct(n,ba);
	num=dotProduct(n,ac);
	t=-num/denom;
	point ret(a.x+t*(b.x-a.x),a.y+t*(b.y-a.y));
	return ret;
}

inline double triarea(point a,point b,point c)
{
	return 0.5*mabs((a.x-b.x)*(b.y-c.y)-(a.y-b.y)*(b.x-c.x));
}

int flag;

double arc_area(point A,point B)
{
	point O;
	double ang=angle_bac(A,O,B);
	double ret=(ang/2.)*sq(britto.rad)-triarea(O,A,B);
	if(E(triarea(I,O,A)+triarea(I,O,B)+triarea(O,A,B),triarea(I,A,B)))
		flag=1;
	return ret;
}

int main()
{
	double h,a1,a2,a3,a4,ans1,ans2;
	point A,B,C,D;
	britto.cx=britto.cy=0;
	while(scanf("%lf%lf",&britto.rad,&h)==2)
	{
		scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y);
		scanf("%lf%lf%lf%lf",&C.x,&C.y,&D.x,&D.y);
		
		vector<point> now=circle_line(britto,pts2line(A,B));
		if(now.size()<2)
			while(1);
		point p=now[0],q=now[1];
		
		now=circle_line(britto,pts2line(C,D));
		if(now.size()<2)
			while(1);
		point r=now[0],s=now[1];
		
		I=intersect(p,q,r,s);
		
		flag=0;		
		a1=arc_area(r,q)+triarea(I,r,q);
		a2=arc_area(r,p)+triarea(I,r,p);
		a3=arc_area(q,s)+triarea(I,q,s);
		a4=arc_area(p,s)+triarea(I,p,s);
		
		ans1=Min(Min(a1,a2),Min(a3,a4));
		ans2=Max(Max(a1,a2),Max(a3,a4));
		
		if(!flag)
			if(E(ans2,a1))
				ans2-=triarea(I,r,q),ans2=pye*sq(britto.rad)-ans2,ans2+=triarea(I,r,q);
			else if(E(ans2,a2))
				ans2-=triarea(I,r,p),ans2=pye*sq(britto.rad)-ans2,ans2+=triarea(I,r,p);
			else if(E(ans2,a3))
				ans2-=triarea(I,q,s),ans2=pye*sq(britto.rad)-ans2,ans2+=triarea(I,q,s);
			else
				ans2-=triarea(I,p,s),ans2=pye*sq(britto.rad)-ans2,ans2+=triarea(I,p,s);

		printf("%.2lf %.2lf\n",ans2*h,ans1*h);
	}
	return 0;
}
