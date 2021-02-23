/*this is my code wa,wa,wa,wa,wa....passed all the cases set by me & the board
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 21000000.
#define pye (2.*acos(0.))
#define eps 1e-7
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
	if(myabs(a.angle-b.angle)<eps)
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
double perpendicular_dist(int k,double m,double c)
{
	if(m==inf)return myabs(hull[k].x-c);
	return (myabs(hull[k].y-m*hull[k].x-c)/sqrt(1+m*m));
}
int main()
{
	int n,i,j,num,start,k;
	double miny,minx,maxx,maxy,area,m,c,perdist,minarea;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		p=(point *)calloc(n,sizeof(point));
		hull=(point *)calloc(n,sizeof(point));
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		if(n<=2)
		{
			printf("0.0000\n");
			free(p);
			free(hull);
			continue;
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
		if(num<3)
		{
			printf("0.0000\n");
			free(p);
			free(hull);
			continue;
		}
		miny=minx=inf;
		maxx=maxy=-inf;
		for(i=0;i<num;i++)
		{
			if(hull[i].x<minx)minx=hull[i].x;
			if(hull[i].y<miny)miny=hull[i].y;
			if(hull[i].x>maxx)maxx=hull[i].x;
			if(hull[i].y>maxy)maxy=hull[i].y;
		}
		minarea=myabs((maxx-minx)*(maxy-miny));
		for(i=0;i<num;i++)
		{
			area=1.;
			if(myabs(hull[(i+1)%num].x-hull[i].x)>eps)
				m=(hull[(i+1)%num].y-hull[i].y)/(hull[(i+1)%num].x-hull[i].x);
			else m=inf;
			if(m!=inf)c=hull[i].y-m*hull[i].x;
			else c=hull[i].x;	
			for(j=(i+2)%num,maxy=-inf;j!=i;j=(j+1)%num)
			{
				perdist=perpendicular_dist(j,m,c);
				if(perdist>maxy)
				{
					maxy=perdist;
					k=j;
				}
			}
			area*=maxy;
			if(m==inf)m=0.;
			else if(m>eps)m=-1./m;
			else m=inf;
			if(m!=inf)c=hull[k].y-m*hull[k].x;
			else c=hull[k].x;
			for(j=(k-1+num)%num,minx=-inf;j!=i;j=(j-1+num)%num)
			{
				perdist=perpendicular_dist(j,m,c);
				if(perdist>minx)minx=perdist;
			}
			for(j=(k+1)%num,maxx=-inf;j!=((i+1)%num);j=(j+1)%num)
			{
				perdist=perpendicular_dist(j,m,c);
				if(perdist>maxx)maxx=perdist;
			}
			area*=(maxx+minx);
			if(area<minarea)minarea=area;
		}
		printf("%.4lf\n",minarea+eps);
		free(p);
		free(hull);
	}
	return 0;
}*/
//this is code from Kallol-AC
# include <stdio.h>
# include <math.h>

typedef struct{
  double x,y;
}Point;

enum region { LEFT=0,RIGHT,BEHIND,BEYOND,ORIGIN,DESTINATION,BETWEEN};

int classify(Point p0,Point p1,Point p2)
{
  Point a,b;
  double t;
  a.x=p1.x-p0.x;
  a.y=p1.y-p0.y;
  b.x=p2.x-p0.x;
  b.y=p2.y-p0.y;
  t=a.x*b.y-a.y*b.x;
  if(t>0.0) return LEFT;
  if(t<0.0) return RIGHT;
  if((a.x*a.x+a.y*a.y)<(b.x*b.x+b.y*b.y)) return BEYOND;
  if((a.x>0.0 && b.x<0.0) || (a.x<0.0 && b.x>0.0)) return BEHIND;
  if((a.y>0.0 && b.y<0.0) || (a.y<0.0 && b.y>0.0)) return BEHIND;
  if(p0.x==p2.x && p0.y==p2.y) return ORIGIN;
  if(p1.x==p2.x && p1.y==p2.y) return DESTINATION;
  return BETWEEN;
}

void swap(Point *a,Point *b)
{
  Point t=*a;
  *a=*b;
  *b=t;
}

int GiftWrapHull(Point s[],int n)
{
  int a,i,m,c;
  for(a=0,i=1;i<n;i++)
    if(s[i].y<s[a].y || (s[i].y==s[a].y && s[i].x<s[a].x))
      a=i;
  s[n]=s[a];
  for(m=0;m<n;m++){
    swap(&s[a],&s[m]);
    a=m+1;
    for(i=m+2;i<=n;i++){
      c=classify(s[m],s[a],s[i]);
      if(c==RIGHT || c==BETWEEN)
	a=i;
    }
    if(a==n) break;
  }
  s[++m]=s[0];
  return m+1;
}

double dotProduct(Point a,Point b)
{
  return a.x*b.x+a.y*b.y;
}

int main(void)
{
  int n,m;
  Point p[1001];
  double x,y;
  double area,left,right,height;
  double tlr,th,tw,ta,aval;
  Point a,b,normal;
  int i,j;
  while(scanf("%d",&n)==1 && n){
    for(i=0;i<n;i++){
      scanf("%lf%lf",&x,&y);
      p[i].x=x;
      p[i].y=y;
    }
    if(n<=2) area=0.0;
    else{
      m=GiftWrapHull(p,n);
      area=-1;
      for(i=0;i<m-1;i++){
	a.x=p[i+1].x-p[i].x;
	a.y=p[i+1].y-p[i].y;
	aval=sqrt(dotProduct(a,a));
	a.x/=aval;
	a.y/=aval;
	left=right=height=0;
	for(j=0;j<m-1;j++){
	  b.x=p[j].x-p[i].x;
	  b.y=p[j].y-p[i].y;
	  tlr=dotProduct(a,b);
	  normal.x=a.y;
	  normal.y=-a.x;
	  th=dotProduct(normal,b);
	  if(th<0.0) th=-th;
	  if(tlr<left) left=tlr;
	  if(tlr>right) right=tlr;
	  if(th>height) height=th;
	}
	tw=right-left;
	ta=tw*height;
	if(area==-1 || ta<area) area=ta;
      }
    }
    printf("%.4lf\n",area);
  }
  return 0;
}













