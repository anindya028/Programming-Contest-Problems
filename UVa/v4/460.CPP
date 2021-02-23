#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

#define myabs(a) (((a)>0)?(a):-(a))
#define eps 1e-8
#define SIZE 100

struct Point
{
  double x,y;
  Point(double x0=0,double y0=0){x=x0;y=y0;}
  void ini(double x0,double y0){x=x0;y=y0;}
};

inline bool equal(double a,double b)
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
    if(denom==0.0)
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
		orgIsInside=(classify(a,b,org)!=LEFT);//We can modify this according to our need->in which direction 
		destIsInside=(classify(a,b,dest)!=LEFT);//we want to clip->right or left.Here left is needed.
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
//clipping subject polygon with clipper->clipper must be convex.
//runs in O(m*n) time
int polygonClip(Point subject[],int m,Point clipper[],int n)
{
	int tm;
	int i;
	clipper[n]=clipper[0];
	for(i=0;i<n;i++)
	{
		tm=lineClip(clipper[i],clipper[i+1],subject,m);
		m=tm;
	}
	return m;
}	

int main()
{
	Point s[5],c[5];
	int t,tm,xl,yl,xr,yr,i,cs;
	double a;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");

		scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
		s[0].ini(xl,yl);
		s[1].ini(xl,yr);
		s[2].ini(xr,yr);
		s[3].ini(xr,yl);
		scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
		c[0].ini(xl,yl);
		c[1].ini(xl,yr);
		c[2].ini(xr,yr);
		c[3].ini(xr,yl);
		tm=polygonClip(s,4,c,4);
		a=area(s,tm);
		if(a<eps)
		{
			printf("No Overlap\n");
			continue;
		}
		xl=yl=1000000000;
		xr=yr=-100000000;
		for(i=0;i<4;i++)
		{
			if(s[i].x>xr)
				xr=s[i].x;
			if(s[i].x<xl)
				xl=s[i].x;
			if(s[i].y>yr)
				yr=s[i].y;
			if(s[i].y<yl)
				yl=s[i].y;
		}
		if(xl>=xr || yl>=yr)
		{
			printf("No Overlap\n");
			continue;
		}
		printf("%d %d %d %d\n",xl,yl,xr,yr);
	}
	return 0;
}

