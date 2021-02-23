//Convex-hull
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
	if(n==2)
		return ns;
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
int main()
{
	int n,cs,i,j,count,start,num;
	double x,y,w,h,theta,totarea,conarea,x1,x2,y1,y2;
	scanf("%d",&cs);
	for(j=0;j<cs;j++)
	{
		scanf("%d",&n);
		p=(point *)calloc((4*n),sizeof(point));
		hull=(point *)calloc((4*n),sizeof(point));
		totarea=conarea=0.;
		for(i=count=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&h,&theta);
			totarea+=(w*h);
			theta=theta*pye/180.;
			if(w<eps && h<eps)
			{
				p[count].x=x;
				p[count].y=y;
				count++;
			}
			else if(w<eps)
			{
				x1=x+h*sin(theta)/2.;
				y1=y+h*cos(theta)/2.;
				p[count].x=x1;
				p[count].y=y1;
				p[count+1].x=2*x-x1;
				p[count+1].y=2*y-y1;
				count+=2;
			}
			else if(h<eps)
			{
				x2=x+w*cos(theta)/2.;
				y2=y+w*sin(theta)/2.;
				p[count].x=x2;
				p[count].y=y2;
				p[count+1].x=2*x-x2;
				p[count+1].y=2*y-y2;
				count+=2;
			}
			else
			{
				x1=(2*x+h*sin(theta)-w*cos(theta))/2.;
				x2=(w*cos(theta)+2*x+h*sin(theta))/2.;
				y1=(2*y+h*cos(theta)+w*sin(theta))/2.;
				y2=(-w*sin(theta)+2*y+h*cos(theta))/2.;
				p[count].x=x1;
				p[count].y=y1;
				p[count+1].x=x2;
				p[count+1].y=y2;
				count+=2;
				p[count].x=2*x-x1;
				p[count].y=2*y-y1;
				p[count+1].x=2*x-x2;
				p[count+1].y=2*y-y2;
				count+=2;
			}
		}
		start=findstart(count);
		for(i=0;i<count;i++)
		{
			p[i].dist=sqrt((p[i].x-p[start].x)*(p[i].x-p[start].x)+(p[i].y-p[start].y)*(p[i].y-p[start].y));
			if(i!=start)p[i].angle=getangle(p[i].x-p[start].x,p[i].y-p[start].y);
			else p[i].angle=0.0;
		}
		sort(p,p+count);
		num=convex_hull(count);
		/*for(i=0;i<num;i++)
			printf("%.5lf %.5lf\n",hull[i].x,hull[i].y);*/
		for(i=0;i<num;i++)
			conarea+=(hull[i].x*hull[(i+1)%num].y);
		for(i=0;i<num;i++)
			conarea-=(hull[i].y*hull[(i+1)%num].x);
		conarea*=.5;
		printf("%.1lf %%\n",totarea*100./conarea);
		free(p);
		free(hull);
	}
	return 0;
}













