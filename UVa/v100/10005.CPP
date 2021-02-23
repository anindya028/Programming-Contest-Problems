//Minimal circle O(n^3)
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Max(a,b) ((a>b)?(a):(b))
#define myabs(a) ((a>0)?(a):-(a))
#define eps 1e-12
struct point
{
	double x,y;
}p[105];
double triarea(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return 0.5*((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3));
}
bool on_line(point a,point b,point c)
{
	if(myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))<eps)
		return true;
	return false;
}
bool obtuse_tri(double d1,double d2,double d3)
{
	return (((d1*d1+d2*d2)<d3*d3) || ((d3*d3+d2*d2)<d1*d1) || ((d1*d1+d3*d3)<d2*d2));
}
double circle3pts(point a,point b,point c)
{
	double d1,d2,d3;
	d1=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	d2=sqrt((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y));
	d3=sqrt((c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y));
	if(on_line(a,b,c) || obtuse_tri(d1,d2,d3))
		return (Max(d1,Max(d2,d3))/2.);
	else
		return (d1*d2*d3)/(4*myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y)));
}
int main()
{
	int n,i,j,k;
	double r,max,dist;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		scanf("%lf",&r);
		if(n==1)
		{
			printf("The polygon can be packed in the circle.\n");
			continue;
		}
		else if(n==2)
		{
			max=sqrt((p[0].x-p[1].x)*(p[0].x-p[1].x)+(p[0].y-p[1].y)*(p[0].y-p[1].y));
			if(max>(2*r))
				printf("There is no way of packing that polygon.\n");
			else
				printf("The polygon can be packed in the circle.\n");	
			continue;
		}
		max=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				for(k=j+1;k<n;k++)
				{
					dist=circle3pts(p[i],p[j],p[k]);
					if(dist>max)
						max=dist;
				}
		
		if(max>r)
			printf("There is no way of packing that polygon.\n");
		else
			printf("The polygon can be packed in the circle.\n");
	}
	return 0;
}













