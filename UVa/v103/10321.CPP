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

}pol1[105],pol2[105],p[100005];

inline double det(double a,double b,double c,double d)
{
	return (a*d-b*c);
}

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

bool lineseg_lineseg(point a,point b,point c,point d)//checks whether AB & CD intersects or not
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

point inter(point a,point b,point c,point d)
{
	double a1,a2,b1,b2,c1,c2;//ax+by+c=0
	point inters;
	a1=a.y-b.y;
	b1=b.x-a.x;
	c1=a.x*b.y-b.x*a.y;
	a2=c.y-d.y;
	b2=d.x-c.x;
	c2=c.x*d.y-d.x*c.y;
	inters.x=det(-c1,b1,-c2,b2)/det(a1,b1,a2,b2);
	inters.y=det(a1,-c1,a2,-c2)/det(a1,b1,a2,b2);
	return inters;
}

bool interior(point a,point b,point c)//for determining whether a point is within line segment
{
	if((int)c.x<=(int)max(a.x,b.x) && (int)c.x>=(int)min(a.x,b.x) && (int)c.y<=(int)max(a.y,b.y) && (int)c.y>=(int)min(a.y,b.y))
		return true;
	else return false;
}

int inpoly1(int n,point p)
{
	int i,counter=0;
	double xinters;
	point p1,p2;
	p1=pol1[0];
	for(i=0;i<n;i++)
		if(on_line(pol1[i],pol1[(i+1)%n],p) && interior(pol1[i],pol1[(i+1)%n],p))
			return (inside);
	if(n==2)
		return (outside);
	for(i=1;i<=n;i++)
	{
		p2=pol1[i%n];
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

int inpoly2(int n,point p)
{
	int i,counter=0;
	double xinters;
	point p1,p2;
	p1=pol2[0];
	for(i=0;i<n;i++)
		if(on_line(pol2[i],pol2[(i+1)%n],p) && interior(pol2[i],pol2[(i+1)%n],p))
			return (inside);
	if(n==2)
		return (outside);
	for(i=1;i<=n;i++)
	{
		p2=pol2[i%n];
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

bool operator<(point a,point b)
{
	if(myabs(a.x-b.x)<eps)
		return a.y<b.y;
	return a.x<b.x;
}

int main()
{
	int i,cnt,n,m,j,k;	
	while(scanf("%d",&n)==1 && n>=3)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf",&pol1[i].x,&pol1[i].y);
		scanf("%d",&m);
		if(m<3)
			break;
		for(i=0;i<m;i++)
			scanf("%lf%lf",&pol2[i].x,&pol2[i].y);
		for(i=k=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(lineseg_lineseg(pol1[i],pol1[(i+1)%n],pol2[j],pol2[(j+1)%m]))
				{
					p[k]=inter(pol1[i],pol1[(i+1)%n],pol2[j],pol2[(j+1)%m]);
					k++;
				}
			}
		for(i=0;i<m;i++)
			if(inpoly1(n,pol2[i])==inside)
			{
				p[k]=pol2[i];
				k++;
			}

		for(i=0;i<n;i++)
			if(inpoly2(m,pol1[i])==inside)
			{
				p[k]=pol1[i];
				k++;
			}
		sort(p,p+k);
		for(i=cnt=0;i<k;i++)
		{
			if(!i || !samepoint(p[i-1],p[i]))
				cnt++;
		}
		printf("%d\n",cnt);
		for(i=0;i<k;i++)
		{
			if(!i || !samepoint(p[i-1],p[i]))
				printf("%.2lf %.2lf\n",p[i].x,p[i].y);
		}
		
	}
	return 0;
}
