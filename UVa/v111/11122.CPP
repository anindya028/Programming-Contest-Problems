//Computational Geometry
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define eps 1e-9
#define inf 100000000.
#define myabs(a) (((a)>0)?(a):-(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define tria(p,q,r) myabs(triarea(p.x,p.y,q.x,q.y,r.x,r.y))

struct point 
{
	double x,y;
}A[3],B[3];

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

bool linseg_linseg(point a,point b,point c,point d)//checks whether AB & CD intersects or not
{
	double m1,m2;
	if(on_line(a,b,c) || on_line(a,b,d) || on_line(c,d,a) || on_line(c,d,b))
		return false;
	if(myabs(b.x-a.x)<eps)m1=inf;
	else m1=(b.y-a.y)/(b.x-a.x);
	if(myabs(d.x-c.x)<eps)m2=inf;
	else m2=(d.y-c.y)/(d.x-c.x);
	if(myabs(m1-m2)<eps)
		return false;
	
	else
	{
		if((right_turn(a,b,c) ^ right_turn(a,b,d)) && (right_turn(c,d,a) ^ right_turn(c,d,b)))
			return true;
		return false;
	}
}

bool a_in_b(void)
{
	double area_b=tria(B[0],B[1],B[2]);
	double area;
	int i;
	for(i=0;i<3;i++)
	{
		area=tria(A[i],B[0],B[1])+tria(A[i],B[1],B[2])+tria(A[i],B[2],B[0]);
		if(myabs(area-area_b)>eps)
			return false;
	}
	return true;
}

bool b_in_a(void)
{
	point temp[3];
	int i;
	for(i=0;i<3;i++)
	{
		temp[i]=A[i];
		A[i]=B[i];
		B[i]=temp[i];
	}
	return a_in_b();
}

bool edge_in_tri(point a,point b,point tri[])
{
	point mid;
	mid.x=(a.x+b.x)/2;
	mid.y=(a.y+b.y)/2;
	if(on_line(mid,tri[0],tri[1]) || on_line(mid,tri[1],tri[2]) || on_line(mid,tri[2],tri[0]))
		return false;
	double area_t=tria(tri[0],tri[1],tri[2]);
	double area=tria(mid,tri[0],tri[1])+tria(mid,tri[1],tri[2])+tria(mid,tri[2],tri[0]);
	return myabs(area_t-area)<eps;
}

int main()
{
	int t,cs,i,j;
	bool flag;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		for(i=0;i<3;i++)
			scanf("%lf%lf",&A[i].x,&A[i].y);
		for(i=0;i<3;i++)
			scanf("%lf%lf",&B[i].x,&B[i].y);
		flag=false;
		//checking intesection of edges->intersection here does not include touching each other
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				if(linseg_linseg(A[i],A[(i+1)%3],B[j],B[(j+1)%3]))
					flag=true;
		//checking edges if inside of triangle  
		for(i=0;i<3;i++)
			if(edge_in_tri(A[i],A[(i+1)%3],B))
				flag=true;
		for(i=0;i<3;i++)
			if(edge_in_tri(B[i],B[(i+1)%3],A))
				flag=true;
		//checking if one is completely within another 
		if(a_in_b())
			flag=true;
		if(b_in_a())
			flag=true;
		//decision
		if(flag)
			printf("pair %d: yes\n",cs+1);
		else
			printf("pair %d: no\n",cs+1);
	}
	return 0;
}


