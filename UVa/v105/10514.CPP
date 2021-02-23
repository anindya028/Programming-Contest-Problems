#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define eps 1e-9
#define inf 100000000.
#define myabs(a) (((a)>0)?(a):-(a))
#define Min(a,b) (((a)<(b))?(a):(b))

struct point
{
	double x,y;
};

struct polygon
{
	point p[105];
	int num;
}node[15];

inline double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
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
//determines point to line perpendicular distance
double point_to_line(point p,point a,point b)
{
	double m,c;
	if(myabs(a.x-b.x)<eps)
	{
		m=inf;
		c=-a.x;
	}
	else
	{
		m=(a.y-b.y)/(a.x-b.x);
		c=a.y-m*a.x;
	}
	if(myabs(m-inf)<eps)return myabs(p.x+c);
	else return (myabs(p.y-m*p.x-c)/sqrt(1+m*m));
}

//determines line segment(AB) to line(CD) shortest distance
double line_seg_to_line(point a,point b,point c,point d)
{
	double m1,m2,c1,c2;
	if(on_line(a,c,d) || on_line(b,c,d))
        return 0.;
	if(myabs(a.x-b.x)<eps)
	{
		m1=inf;
		c1=-a.x;
	}
	else
	{
		m1=(a.y-b.y)/(a.x-b.x);
		c1=a.y-m1*a.x;
	}
	if(myabs(c.x-d.x)<eps)
	{
		m2=inf;
		c2=-c.x;
	}
	else
	{
		m2=(c.y-d.y)/(c.x-d.x);
		c2=c.y-m2*c.x;
	}
	if(myabs(m1-m2)<eps)
	{
		if(on_line(a,c,d))return 0.;
		else return point_to_line(a,c,d);
	}
	else
	{
		if(right_turn(a,c,d) ^ right_turn(b,c,d))
			return 0.;
		return Min(point_to_line(a,c,d),point_to_line(b,c,d));
	}
}
//determines whether a perpendicular exists from P to line segment AB
bool perpendicular_exist(point p,point a,point b)
{
	double m,c;
	point q;
	if(myabs(a.y-b.y)<eps)
	{
		m=inf;
		c=-p.x;
	}
	else
	{
		m=-(a.x-b.x)/(a.y-b.y);
		c=p.y-m*p.x;
	}
	if(myabs(m-inf)<eps)
	{
		q.x=p.x;
		q.y=p.y+10;
	}
	else
	{
		q.x=p.x+10.;
		q.y=m*q.x+c;
	}
	if(line_seg_to_line(a,b,p,q)<eps)return true;
	else return false;
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
//determines line segment(AB) to line segment(CD) shortest distance
double line_seg_to_line_seg(point a,point b,point c,point d)
{
	double mn;
	if(lineseg_lineseg(a,b,c,d))
		return 0.;
	mn=Min(Min(dist(a,c),dist(a,d)),Min(dist(b,c),dist(b,d)));
	if(perpendicular_exist(a,c,d))
		mn=Min(mn,point_to_line(a,c,d));
	if(perpendicular_exist(b,c,d))
		mn=Min(mn,point_to_line(b,c,d));
	if(perpendicular_exist(c,a,b))
		mn=Min(mn,point_to_line(c,a,b));
	if(perpendicular_exist(d,a,b))
		mn=Min(mn,point_to_line(d,a,b));
	return mn;
}

double mat[15][15];

int main()
{
	int r1,r2,n,m,i,j,k,cs,l;
	double mn,d;
	scanf("%d",&cs);
	while(cs--)
	{
		scanf("%d%d%d",&r1,&r2,&n);
		for(i=0;i<r1;i++)
			scanf("%lf%lf",&node[0].p[i].x,&node[0].p[i].y);
		node[0].num=r1;
		for(i=0;i<r2;i++)
			scanf("%lf%lf",&node[1].p[i].x,&node[1].p[i].y);
		node[1].num=r2;
		for(i=2;i<n+2;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
				scanf("%lf%lf",&node[i].p[j].x,&node[i].p[j].y);
			node[i].p[j]=node[i].p[0];
			node[i].num=m+1;
		}
		n=n+2;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(j==i)
				{
					mat[i][j]=0;
					continue;
				}
				mn=inf;
				for(k=0;k<node[i].num-1;k++)
					for(l=0;l<node[j].num-1;l++)
					{
						d=line_seg_to_line_seg(node[i].p[k],node[i].p[k+1],node[j].p[l],node[j].p[l+1]);
						mn=Min(mn,d);
					}
				mat[i][j]=mat[j][i]=mn;
			}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					mat[i][j]=Min(mat[i][j],mat[i][k]+mat[k][j]);
		printf("%.3lf\n",mat[0][1]);
	}
	return 0;
}

