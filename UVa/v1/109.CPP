#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 21000000.
#define pye (2.*acos(0.))
#define eps 1e-12
#define myabs(a) ((a>0)?(a):-(a))
struct point 
{
	double x,y,angle,dist;
}*p,*hull,king[100][100];
double area[100];
int on[100],numpoint[100];
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
	double sum=0.,minx=inf,miny=inf,maxx=-inf,maxy=-inf;
	if(numpoint[n]<=2)return false;
	for(i=0;i<numpoint[n];i++)
	{
		sum+=myabs(triarea(king[n][i].x,king[n][i].y,king[n][(i+1)%numpoint[n]].x,king[n][(i+1)%numpoint[n]].y,x,y));
		if(king[n][i].x<minx)minx=king[n][i].x;
		if(king[n][i].y<miny)miny=king[n][i].y;
		if(king[n][i].x>maxx)maxx=king[n][i].x;
		if(king[n][i].y>maxy)maxy=king[n][i].y;
	}
	if(minx>x || miny>y || maxx<x ||maxy<y)return false;
	if(myabs(sum-area[n])<eps)return true;
	else return false;
}
int main()
{
	int i,j,num,start,n,k=0;
	double x,y,totarea=0.;
	while(scanf("%d",&n)==1)
	{
		if(n==-1)break;
		p=(point *)calloc(n,sizeof(point));
		hull=(point *)calloc(n,sizeof(point));
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		start=findstart(n);
		for(j=0;j<n;j++)
		{
			p[j].dist=sqrt((p[j].x-p[start].x)*(p[j].x-p[start].x)+(p[j].y-p[start].y)*(p[j].y-p[start].y));
			if(j!=start)p[j].angle=getangle(p[j].x-p[start].x,p[j].y-p[start].y);
			else p[j].angle=0.0;
		}
		sort(p,p+n);
		num=convex_hull(n);
		for(j=0;j<num;j++)
		{
			king[k][j].x=hull[j].x;
			king[k][j].y=hull[j].y;
		}
		for(j=area[k]=0;j<num;j++)
			area[k]+=(hull[j].x*hull[(j+1)%num].y);
		for(j=0;j<num;j++)
			area[k]-=(hull[j].y*hull[(j+1)%num].x);
		area[k]*=0.5;
		numpoint[k]=num;
		k++;
		free(p);
		free(hull);
	}
	while(scanf("%lf%lf",&x,&y)==2)
	{
		for(i=0;i<k;i++)
			if(inside(x,y,i))
				on[i]=1;
	}
	for(i=0;i<k;i++)
		if(on[i])
			totarea+=area[i];
	printf("%.2lf\n",totarea);
	return 0;
}













