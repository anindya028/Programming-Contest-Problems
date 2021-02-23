#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define pye (2.*acos(0.))
#define eps 1e-12
#define myabs(a) ((a>0)?(a):-(a))
struct point 
{
	double x,y,angle,dist;
}*p,*hull;
double area;
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
bool on_line(point a,point b,point c)
{
	if(myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))<eps)
		return true;
	return false;
}
int convex_hull(int n)
{
	int i=2,ns=2;
	hull[0].x=p[0].x;
	hull[0].y=p[0].y;
	hull[1].x=p[1].x;
	hull[1].y=p[1].y;
	while(on_line(p[0],p[1],p[i]))
	{
		i++;
		if(i==n)
		{
			hull[1].x=p[n-1].x;
			hull[1].y=p[n-1].y;
			return ns;
		}
	}
    for(i=2;i<n;i++)
	{
		while(ns>=2)
		{
			if(right_turn(hull[ns-2],hull[ns-1],p[i]))
				ns--;
			else break;
		}
		hull[ns].x=p[i].x;
		hull[ns].y=p[i].y;
		ns++;
	}
	while(ns>=4 && right_turn(hull[ns-2],hull[ns-1],hull[0]))
		ns--;
	return ns;
}
bool inside(double x,double y,int n)
{
	int i;
	double sum=0.;
	for(i=0;i<n;i++)
		sum+=myabs(triarea(hull[i].x,hull[i].y,hull[(i+1)%n].x,hull[(i+1)%n].y,x,y));
	if(myabs(sum-area)<eps)return true;
	else return false;
}
int main()
{
	int s1,s2,s3,n,num,i,j,start;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		p=(point *)calloc(n,sizeof(point));
		hull=(point *)calloc(n,sizeof(point));
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&s1,&s2,&s3);
			p[i].x=s2-s1;
			p[i].y=s3-s1;
		}
		start=findstart(n);
		for(j=0;j<n;j++)
		{
			p[j].dist=sqrt((p[j].x-p[start].x)*(p[j].x-p[start].x)+(p[j].y-p[start].y)*(p[j].y-p[start].y));
			if(j!=start)p[j].angle=getangle(p[j].x-p[start].x,p[j].y-p[start].y);
			else p[j].angle=0.0;
		}
		sort(p,p+n);
		num=convex_hull(n);
		for(j=area=0;j<num;j++)
			area+=(hull[j].x*hull[(j+1)%num].y);
		for(j=0;j<num;j++)
			area-=(hull[j].y*hull[(j+1)%num].x);
		area*=.5;
		if(inside(0,0,num))
			printf("Yes\n");
		else
			printf("No\n");
		free(p);
		free(hull);
	}
	return 0;
}













