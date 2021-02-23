#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define inf 21000000.
#define pye (2.*acos(0.))
#define eps 1e-12
#define myabs(a) ((a>0)?(a):-(a))
struct point 
{
	double x,y,angle,dist;
}p[1000],hull[1000];

inline double _dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double getangle(double dx,double dy)
{
	if(dx==0.)
	{
		if(dy>0.)return pye/2;
		else return 3.*pye/2;
	}
	else if(dy==0.)
	{
		if(dx>0.)return 0.;
		else return pye;
	}
	if(atan2(dy,dx)<0.)return atan2(dy,dx)+2.*pye;
	return atan2(dy,dx);
}

int findstart(int n)
{
	int i,k=0;
	double miny=p[k].y;
	for(i=1;i<n;i++)
	{
		if(p[i].y==miny)
		{
			if(p[i].x<p[k].x)
			{
				k=i;
			}
		}
		else if(p[i].y<miny)
		{
			miny=p[i].y;
			k=i;
		}
	}
	return k;
}

bool operator<(point a,point b)
{
	if(myabs(a.angle-b.angle)<=eps)
		return a.dist<b.dist;
	return a.angle<b.angle;
}

inline double triarea(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return 0.5*((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3));
}

inline bool on_line(point a,point b,point c)
{
	if(myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))<eps)
		return true;
	return false;
}

inline bool right_turn(point a,point b,point c)
{
	if(on_line(a,b,c))
		return false;
	if(triarea(a.x,a.y,b.x,b.y,c.x,c.y)>0.)
		return false;
	else return true;
}

inline bool same_point(point a,point b)
{
	return myabs(a.x-b.x)<eps && myabs(a.y-b.y)<eps;
}

int convex_hull(int n)
{
	int i=2,ns=2;
	hull[0].x=p[0].x;
	hull[0].y=p[0].y;
	hull[1].x=p[1].x;
	hull[1].y=p[1].y;
	/*while(on_line(p[0],p[1],p[i]))
	{
		i++;
		if(i==n)
		{
			hull[1].x=p[n-1].x;
			hull[1].y=p[n-1].y;
			return ns;
		}
	}*/
    for(i=2;i<n;i++)
	{
		while(ns>=2)
		{
			if(right_turn(hull[ns-2],hull[ns-1],p[i]))
				ns--;
			else break;
		}
		if(same_point(p[i],hull[ns-1]))
			continue;
		hull[ns].x=p[i].x;
		hull[ns].y=p[i].y;
		ns++;
	}
	while(ns>=4 && right_turn(hull[ns-2],hull[ns-1],hull[0]))
		ns--;
	return ns;
}

int main()
{
	char c,ident[1000],s[10];
	register int i;
	int n,num,t,k;
	double miny;
	while(gets(ident))
	{
		if(ident[0]=='E')break;
		//gets(ident);
		n=0;
		while(cin.get(c) && c=='P')
		{
			scanf("%d",&t);
			for(i=0;i<t;i++)
			{
				scanf("%lf%lf",&p[n].x,&p[n].y);
				n++;
			}
			cin.get(c);
		}
		cin.unget();
		k=findstart(n);
		for(i=0;i<n;i++)
		{
			p[i].dist=_dist(p[i],p[k]);
			if(i!=k)p[i].angle=getangle(p[i].x-p[k].x,p[i].y-p[k].y);
			else p[i].angle=0;
		}
		sort(p,p+n);
		num=convex_hull(n);
		k=0;
		miny=hull[0].y;
		for(i=1;i<num;i++)
		{
			if(hull[i].x>hull[k].x)
			{
				k=i;
				miny=hull[k].y;
			}
			else if(myabs(hull[i].x-hull[k].x)<eps && hull[i].y<miny)
			{
				k=i;
				miny=hull[k].y;
			}
		}
		for(i=0;ident[i]!=' ';i++);
		for(i++;ident[i];i++)
			printf("%c",ident[i]);
		printf(" convex hull:\n");
		printf(" (%.0lf,%.0lf)",hull[k].x,hull[k].y);
		for(i=(k+1)%num;;i=(i+1)%num)
		{
			if(i==k)break;
			printf(" (%.0lf,%.0lf)",hull[i].x,hull[i].y);
		}
		printf("\n");
	}
	return 0;
}













