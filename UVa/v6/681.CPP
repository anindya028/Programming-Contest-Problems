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
	for(i=1;i<n-1;i++)
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
bool right_turn(int n1,int n2,int n3)
{
	if(triarea(hull[n1].x,hull[n1].y,hull[n2].x,hull[n2].y,p[n3].x,p[n3].y)>0.)
		return false;
	else return true;
}
bool fright_turn(int n1,int n2)
{
	if(triarea(hull[n1].x,hull[n1].y,hull[n2].x,hull[n2].y,hull[0].x,hull[0].y)>0.)
		return false;
	else return true;
}
bool on_line(int n1,int n2,int n3)
{
	if(myabs(triarea(hull[n1].x,hull[n1].y,hull[n2].x,hull[n2].y,p[n3].x,p[n3].y))<eps)
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
	while(on_line(0,1,i))
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
			if(right_turn(ns-2,ns-1,i))
				ns--;
			else break;
		}
		hull[ns].x=p[i].x;
		hull[ns].y=p[i].y;
		ns++;
	}
	while(ns>=4 && fright_turn(ns-2,ns-1))
		ns--;
	return ns;
}
int main()
{
	int i,n,k,start,j,num;
	scanf("%d",&k);
	printf("%d\n",k);
	for(i=0;i<k;i++)
	{
		if(i)
		{
			printf("-1\n");
			scanf("%d",&n);
		}
		scanf("%d",&n);
		p=(point *)calloc(n,sizeof(point));
		hull=(point *)calloc(n,sizeof(point));
		for(j=0;j<n;j++)
			scanf("%lf%lf",&p[j].x,&p[j].y);
		start=findstart(n);
		for(j=0;j<n;j++)
		{
			p[j].dist=sqrt((p[j].x-p[start].x)*(p[j].x-p[start].x)+(p[j].y-p[start].y)*(p[j].y-p[start].y));
			if(j!=start)p[j].angle=getangle(p[j].x-p[start].x,p[j].y-p[start].y);
			else p[j].angle=0.0;
		}
		sort(p,p+n);
		num=convex_hull(n);
		hull[num].x=hull[0].x;
		hull[num].y=hull[0].y;
		num++;
		printf("%d\n",num);
		for(j=0;j<num;j++)
			printf("%.0lf %.0lf\n",hull[j].x,hull[j].y);
		free(p);
		free(hull);
	}
	return 0;
}


