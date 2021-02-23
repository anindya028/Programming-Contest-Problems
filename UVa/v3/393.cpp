#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)
#define myabs(a) (((a)>0)?(a):-(a))

struct point
{
	double x,y;
	void ini(double _x,double _y){x=_x,y=_y;}
}p[105];

struct line 
{
	point a,b;
}l[500];

double dist(point a,point b)
{
	return sqrt(sq(a.x-b.x)+sq(a.y-b.y));
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

bool lineseg_lineseg(point a,point b,point c,point d)					//checks whether AB & CD intersects or not
{
	double m1,m2;
	if(myabs(b.x-a.x)<eps)m1=inf;
	else m1=(b.y-a.y)/(b.x-a.x);
	if(myabs(d.x-c.x)<eps)m2=inf;
	else m2=(d.y-c.y)/(d.x-c.x);
	if(samepoint(a,c) || samepoint(a,d) || samepoint(b,c) || samepoint(b,d))
		return false;
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

double mat[105][105];

int main()
{
	int i,n,v,j,k,seg,flag;
	double xx,yy[4];
	while(scanf("%d",&n)==1)
	{
		if(n<0)
			break;
		seg=v=2;
		p[0].ini(0,5);
		p[1].ini(10,5);
		Foro(i,n)
		{
			scanf("%lf",&xx);
			Foro(j,4)
				scanf("%lf",&yy[j]);
			l[seg].a.ini(xx,0);
			l[seg++].b.ini(xx,yy[0]);
			p[v++]=l[seg-1].b;
			p[v++].ini(xx,yy[1]);
			l[seg].a=p[v-1];
			l[seg++].b.ini(xx,yy[2]);
			p[v++]=l[seg-1].b;
			p[v++].ini(xx,yy[3]);
			l[seg].a=p[v-1];
			l[seg++].b.ini(xx,10);
		}
		Foro(i,v)
			Foro(j,v)
				mat[i][j]=(double)(inf);
		Foro(i,v)
			For(j,i+1,v)
			{
				flag=1;
				Foro(k,seg)
					if(lineseg_lineseg(p[i],p[j],l[k].a,l[k].b))
					{
						flag=0;
						break;
					}
				if(flag)
					mat[i][j]=mat[j][i]=dist(p[i],p[j]);
			}
		Foro(k,v)
			Foro(i,v)
				Foro(j,v)
					mat[i][j]=Min(mat[i][j],mat[i][k]+mat[k][j]);
		printf("%.2lf\n",mat[0][1]);
	}
	return 0;
}