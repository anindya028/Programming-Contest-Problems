//LS-LS intersection + Point in Polygon 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;
#define eps 1e-9
#define inf 100000000.
#define myabs(a) (((a)>0)?(a):-(a))
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
#define inside 0
#define outside 1

struct point
{
	double x,y;
};

struct poly_gon
{
	point p[25];
	int n;
}poly[55];

struct line
{
	point a,b;
}l[105];

inline double triarea(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return 0.5*((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3));
}

inline bool right_turn(point a,point b,point c)
{
	if(triarea(a.x,a.y,b.x,b.y,c.x,c.y)>0.)
		return false;
	else return true;
}

inline bool on_line(point a,point b,point c)
{
	if(myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))<eps)
		return true;
	return false;
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

bool lineseg_lineseg(point a,point b,point c,point d)	//checks whether AB & CD intersects or not
{
	double m1,m2;
	if(myabs(b.x-a.x)<eps)m1=inf;
	else m1=(b.y-a.y)/(b.x-a.x);
	if(myabs(d.x-c.x)<eps)m2=inf;
	else m2=(d.y-c.y)/(d.x-c.x);
	if(samepoint(a,c) || samepoint(a,d) || samepoint(b,c) || samepoint(b,d))
		return true;
	if(myabs(m1-m2)<eps)
	{
		if(myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))>eps)
			return false;
		if(interdivide(a,b,c) || interdivide(a,b,d) || interdivide(c,d,a) || interdivide(c,d,b))
			return true;
		else return false;
	}
	else
	{
		if((on_line(a,b,c) && interdivide(a,b,c)) || (on_line(a,b,d) && interdivide(a,b,d)) || (on_line(c,d,a) && interdivide(c,d,a)) || (on_line(c,d,b) && interdivide(c,d,b)))
			return true;
		if((right_turn(a,b,c) ^ right_turn(a,b,d)) && (right_turn(c,d,a) ^ right_turn(c,d,b)))
			return true;
		return false;
	}
}

bool interior(point a,point b,point c)	//for determining whether a point is within line segment
{
	if((int)c.x<=(int)max(a.x,b.x) && (int)c.x>=(int)min(a.x,b.x) && (int)c.y<=(int)max(a.y,b.y) && (int)c.y>=(int)min(a.y,b.y))
		return true;
	else return false;
}
int inpoly(poly_gon polygon,point p)
{
	int i,counter=0;
	double xinters;
	point p1,p2;
	p1=polygon.p[0];
	for(i=0;i<polygon.n;i++)
		if(on_line(polygon.p[i],polygon.p[(i+1)%polygon.n],p) && interior(polygon.p[i],polygon.p[(i+1)%polygon.n],p))
			return (inside);
	if(polygon.n==2)
		return (outside);
	for(i=1;i<=polygon.n;i++)
	{
		p2=polygon.p[i%polygon.n];
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
	if (counter%2==0) return (outside);
	else  return (inside);
}

int main()
{
	int n_l,n_p,i,j,k;
	bool flag;
	while(scanf("%d",&n_l)==1)
	{
		for(i=0;i<n_l;i++)
			scanf("%lf%lf%lf%lf",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
		scanf("%d",&n_p);
		for(i=0;i<n_p;i++)
		{
			scanf("%d",&poly[i].n);
			for(j=0;j<poly[i].n;j++)
				scanf("%lf%lf",&poly[i].p[j].x,&poly[i].p[j].y);
		}
		for(i=0;i<n_l;i++)
		{
			flag=true;
			for(j=0;j<n_p && flag;j++)
			{
				for(k=0;k<poly[j].n;k++)
					if(lineseg_lineseg(l[i].a,l[i].b,poly[j].p[k],poly[j].p[(k+1)%poly[j].n]))
					{
						flag=false;
						printf("Submarine %d is partially on land.\n",i+1);
						break;
					}
				if(flag && inpoly(poly[j],l[i].a)==inside && inpoly(poly[j],l[i].b)==inside)
				{
					flag=false;
					printf("Submarine %d is completely on land.\n",i+1);
				}
			}
			if(flag)
				printf("Submarine %d is still in water.\n",i+1);
		}
	}
	return 0;
}
