#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define inf 1e12
#define eps 1e-9
#define mabs(a) (((a)>0)?(a):-(a))
#define Eq(a,b) (mabs(a-b)<eps)
#define Z(a) E(a,0)
#define sq(a) ((a)*(a))

struct point
{
	double x,y;
	point(){x=0,y=0;}
	point(double x0,double y0){x=x0,y=y0;}
}A,B,C;

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

double triarea(point a,point b,point c)
{
	return 0.5*mabs((a.x-b.x)*(b.y-c.y)-(a.y-b.y)*(b.x-c.x));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
		point D((2*B.x+C.x)/3,(2*B.y+C.y)/3),E((2*C.x+A.x)/3,(2*C.y+A.y)/3),
			F((2*A.x+B.x)/3,(2*A.y+B.y)/3);		

		point p=intersect(A,D,B,E),q=intersect(B,E,C,F),r=intersect(C,F,A,D);
		printf("%.0lf\n",floor(triarea(p,q,r)+.5));		 
	}
	return 0;
}