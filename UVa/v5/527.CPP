#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define inf 100000000.
#define myabs(a) (((a)>0)?(a):-(a))

struct point 
{
	double x,y;
	void ini(double x0,double y0){x=x0;y=y0;}
}sect[100],sq[4];
int k;
struct line
{
	point a,b;
}l[100];

double triarea(point a,point b,point c)
{
	return 0.5*((a.x-b.x)*(b.y-c.y)-(a.y-b.y)*(b.x-c.x));
}

bool samepoint(point a,point b)
{
	return myabs(a.x-b.x)<eps && myabs(a.y-b.y)<eps;
}

int line_line(point a,point b,point c,point d)
{
	double m1,m2,c1,c2,a1,b1,a2,b2,area,temp;
	point p;
	int i;
	if(myabs(a.x-b.x)<eps)m1=inf;
	else m1=(a.y-b.y)/(a.x-b.x);
	//checking if AB is on one side of sq.
	if(myabs(m1-inf)<eps)
	{
		if(myabs(a.x)<eps || myabs(a.x-1000)<eps)
			return -1;
	}
	if(myabs(m1)<0)
	{
		if(myabs(a.y)<eps || myabs(a.y-1000)<eps)
			return -1;
	}

	if(myabs(c.x-d.x)<eps)m2=inf;
	else m2=(c.y-d.y)/(c.x-d.x);
	//parallel
	if(myabs(m1-m2)<eps)
	{
		if(myabs(triarea(a,b,c))<eps)
			return -1;//parallel & on same line->no intersection & no segment
		return 0;//parallel but not on line->no intersection & 1 segment
	}
	else 
	{
		//ax+by+c=0
		a1=b.y-a.y;
		b1=a.x-b.x;
		c1=-(a1*a.x+b1*a.y);
		a2=d.y-c.y;
		b2=c.x-d.x;
		c2=-(a2*c.x+b2*c.y);
		//p is the intersection point
		p.x=(b1*c2-b2*c1)/(a1*b2-a2*b1);
		p.y=(a2*c1-a1*c2)/(a1*b2-a2*b1);
		//checking if p is outside or on the sq.
		for(i=area=0;i<4;i++)
		{
			temp=myabs(triarea(p,sq[i],sq[(i+1)%4]));
			if(temp<eps)
				return 0;
			area+=temp;
		}
		if(myabs(area-1000000.)>eps)
			return 0;
		//checking if it is common with previous points
		for(i=0;i<k;i++)
			if(samepoint(sect[i],p))
				return 0;
		sect[k]=p;//if not,p is a new point
		k++;
		return 1;
	}
}
int main()
{
	int n,i,inter,part[100],j,m,t,cs;
	sq[0].ini(0,0);
	sq[1].ini(0,1000);
	sq[2].ini(1000,1000);
	sq[3].ini(1000,0);
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		if(cs)printf("\n");
		scanf("%d",&n);
		if(!n)
		{
			printf("1\n");
			continue;
		}
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
		part[0]=2;		
		for(i=1;i<n;i++)
		{
			for(j=inter=k=0;j<i;j++)//i-th line er jonno checking koita intersect from 0 to i-1
			{
				m=line_line(l[i].a,l[i].b,l[j].a,l[j].b);
				if(m==-1)//same line is given again->further checking dorkar nai.
					break;
				else
					inter+=m;
			}
			if(m==-1)
				inter=-1;
			part[i]=part[i-1]+inter+1;
		}
		printf("%d\n",part[n-1]);
	}
	return 0;
}













