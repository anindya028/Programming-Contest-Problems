//point inside a polygon-convex,concave=>both
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
#define inside 0
#define outside 1
#define eps 1e-8
#define myabs(a) ((a>0)?(a):-(a))
struct Point
{
	double x,y;
}polygon[1005];
double triarea(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return 0.5*((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3));
}
bool on_line(Point a,Point b,Point c)
{
	if(myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))<eps)
		return true;
	return false;
}
bool interior(Point a,Point b,Point c)//for determining whether a point is within line segment
{
	if((int)c.x<=(int)max(a.x,b.x) && (int)c.x>=(int)min(a.x,b.x) && (int)c.y<=(int)max(a.y,b.y) && (int)c.y>=(int)min(a.y,b.y))
		return true;
	else return false;
}
int inpoly(int n,Point p)
{
	int i,counter=0;
	double xinters;
	Point p1,p2;
	p1=polygon[0];
	for(i=0;i<n;i++)
		if(on_line(polygon[i],polygon[(i+1)%n],p) && interior(polygon[i],polygon[(i+1)%n],p))
			return (inside);
	if(n==2)
		return (outside);
	for(i=1;i<=n;i++)
	{
		p2=polygon[i%n];
		if(p.y>min(p1.y,p2.y))
		{
			if((int)p.y<=(int)max(p1.y,p2.y))
			{
				if(p.x<max(p1.x,p2.x))
				{
					if(myabs(p1.y-p2.y)>eps)
					{
						xinters=(p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
						if(myabs(p1.x-p2.x)<eps || p.x<xinters || myabs(p.x-xinters)<eps)
							counter++;
					}
				}
			}
		}
		p1=p2;
	}
	if(counter%2==0)return (outside);
	else  return (inside);
}
int main()
{
	int n,i,cs=0,m;
	Point p;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&polygon[i].x,&polygon[i].y);
		scanf("%lf%lf",&p.x,&p.y);
		if(n==1)
		{
			if(myabs(p.x-polygon[0].x)<eps && myabs(p.y-polygon[0].y)<eps)
				printf("T\n");
			else
				printf("F\n");
			continue;
		}
		if(inpoly(n,p))printf("F\n");
		else printf("T\n");
	}
	return 0;
}
