#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

#define eps 1e-9
#define inf 100000000.
#define myabs(a) (((a)>0)?(a):-(a))
#define Min(a,b) (((a)<(b))?(a):(b))

struct point
{
	double x,y;
};

inline double triarea(double &x1,double &y1,double &x2,double &y2,double &x3,double &y3)
{
	return ((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3));
}

inline bool right_turn(point &a,point &b,point &c)
{
	if(triarea(a.x,a.y,b.x,b.y,c.x,c.y)>0.)
		return false;
	else return true;
}

inline bool on_line(point &a,point &b,point &c)
{
	if(myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))<eps)
		return true;
	return false;
}

bool interdivide(point &a,point &b,point &c)
{
	if((c.x>a.x && c.x<b.x) || (c.x<a.x && c.x>b.x) || (c.y>a.y && c.y<b.y) || (c.y<a.y && c.y>b.y))
		return true;
	return false;
}

bool samepoint(point &a,point &b)
{
	if(myabs(a.x-b.x)<eps && myabs(a.y-b.y)<eps)
		return true;
	return false;
}

bool lineseg_lineseg(point &a,point &b,point &c,point &d)//checks whether AB & CD intersects or not
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

point pt1[1005],pt2[1005];

int main()
{
	int n,i,j;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&pt1[i].x,&pt1[i].y,&pt2[i].x,&pt2[i].y);
		int f[1005]={0},cnt=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(lineseg_lineseg(pt1[i],pt2[i],pt1[j],pt2[j]))
				{
					f[i]=f[j]=1;
					cnt++;
				}
		for(i=0;i<n;i++)
			if(!f[i])
				cnt+=2;
		printf("%d\n",cnt);
	}
	return 0;
}