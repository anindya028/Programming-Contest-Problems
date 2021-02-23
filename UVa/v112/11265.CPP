//Polygon cipping
//O(n*m)
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;
#define myabs(a) (((a)>0)?(a):-(a))
#define eps 1e-9
# define SIZE 1005

struct Point
{
  double x,y;
  Point(double x0=0,double y0=0){x=x0;y=y0;}
  void ini(double x0=0,double y0=0){x=x0;y=y0;}
};

inline equal(double a,double b)
{
    return myabs(a-b)<eps;
}

enum { LEFT=0,RIGHT,BEHIND,BEYOND,ORIGIN,DESTINATION,BETWEEN};
enum { COLLINEAR=0,PARALLEL,SKEW,SKEW_CROSS,SKEW_NO_CROSS};

/* p2 on which side of p1-p0 */
inline int classify(Point p0,Point p1,Point p2)
{
	Point a(p1.x-p0.x,p1.y-p0.y),b(p2.x-p0.x,p2.y-p0.y);
	double t;
	t=a.x*b.y-a.y*b.x;
	if(t>0.0) return LEFT;
	if(t<0.0) return RIGHT;
	if((a.x*a.x+a.y*a.y)<(b.x*b.x+b.y*b.y)) return BEYOND;
	if((a.x>0.0 && b.x<0.0) || (a.x<0.0 && b.x>0.0)) return BEHIND;
	if((a.y>0.0 && b.y<0.0) || (a.y<0.0 && b.y>0.0)) return BEHIND;
	if(equal(p0.x,p2.x) && equal(p0.y,p2.y)) return ORIGIN;
	if(equal(p1.x,p2.x) && equal(p1.y,p2.y)) return DESTINATION;
	return BETWEEN;
}

inline double dotProduct(Point a,Point b)
{
	return a.x*b.x+a.y*b.y;
}

/* intersection of b-a and d-c : t of b-a */
inline int intersect(Point a,Point b,Point c,Point d,double *t)
{
	double denom,num;
	int aclass;

	Point n(d.y-c.y,c.x-d.x),ba(b.x-a.x,b.y-a.y),ac(a.x-c.x,a.y-c.y);
	denom=dotProduct(n,ba);
    if(equal(denom,0.0))
	{
		aclass=classify(c,d,a);
		if(aclass==LEFT || aclass==RIGHT)
			return PARALLEL;
		else
			return COLLINEAR;
	}
	num=dotProduct(n,ac);
	*t=-num/denom;
	return SKEW;
}

/* clip polygon p[] using edge b-a */
int lineClip(Point a,Point b,Point p[],int n)
{
	Point r[SIZE];
	Point org,dest,crosspt;
	int orgIsInside,destIsInside;
	double t;
	int i,j;
	p[n]=p[0];
	for(i=j=0;i<n;i++)
	{
		org=p[i];//O->orign
		dest=p[i+1];//D->destination
		orgIsInside=(classify(a,b,org)!=LEFT);
		destIsInside=(classify(a,b,dest)!=LEFT);
		if(orgIsInside!=destIsInside)
		{
			intersect(a,b,org,dest,&t);
			crosspt.x=a.x+t*(b.x-a.x);
			crosspt.y=a.y+t*(b.y-a.y);
		}
		if(orgIsInside && destIsInside)
			r[j++]=dest;//O & D both lie in our desired direction->in that direction
						//which we want to clip->output D
		else if(orgIsInside && !destIsInside)
		{
			if(!equal(org.x,crosspt.x) || !equal(org.y,crosspt.y))
				r[j++]=crosspt;//OD crosses from the right of AB to the left.->ouput intersection.
		}
		else if(!orgIsInside && !destIsInside)
			;//OD lie in opposite of our desired direction->no output.
		else
		{
			r[j++]=crosspt;//OD crosses from the left of AB to the right of AB->output intersection,
			if(!equal(dest.x,crosspt.x) || !equal(dest.y,crosspt.y))//then D.
				r[j++]=dest;
		}
	}
	for(i=0;i<j;i++)
		p[i]=r[i];//copy the resultant polygon after clipping.
	return j;
}


double area(Point p[],int n)
{
	int i;
	double t;
	p[n]=p[0];
	for(t=0,i=1;i<=n;i++)
		t+=p[i-1].x*p[i].y-p[i].x*p[i-1].y;
	t/=2;
	if(t<0)
		t*=-1.0;
	return t;
}

int main()
{
	Point p[SIZE],a,b,q;
	int n,h,w,X,Y,i,m,tm,cs=0;
	double ar;
	while(scanf("%d%d%d%d%d",&n,&w,&h,&X,&Y)==5)
	{
		p[0].ini(0,0);
		p[1].ini(0,h);
		p[2].ini(w,h);
		p[3].ini(w,0);
		m=4;
		q.ini(X,Y);
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
			if(classify(a,b,q)==RIGHT)
			{
				tm=lineClip(a,b,p,m);
				m=tm;
			}
			else
			{
				tm=lineClip(b,a,p,m);
				m=tm;
			}
		}
		ar=area(p,m);
		printf("Case #%d: %.3lf\n",++cs,ar);
	}
	return 0;
}

