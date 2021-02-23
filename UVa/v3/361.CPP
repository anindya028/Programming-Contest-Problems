#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 2100000
#define pye (2.*acos(0.))
#define eps 1e-12
#define myabs(a) ((a>0)?(a):-(a))
struct point 
{
	double x,y,angle,dist;
}*p,*hullc,*hullr;
double coparea,robarea;
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
int convex_hull_cop(int n)
{
	int i=2,ns=2;
	hullc[0].x=p[0].x;
	hullc[0].y=p[0].y;
	hullc[1].x=p[1].x;
	hullc[1].y=p[1].y;
	while(on_line(p[0],p[1],p[i]))
	{
		hullc[i].x=p[i].x;
		hullc[i].y=p[i].y;
		i++;
		ns++;
		if(i==n)
			return ns;
	}
    for(i=2;i<n;i++)
	{
		while(ns>=2)
		{
			if(right_turn(hullc[ns-2],hullc[ns-1],p[i]))
				ns--;
			else break;
		}
		hullc[ns].x=p[i].x;
		hullc[ns].y=p[i].y;
		ns++;
	}
	while(ns>=4 && right_turn(hullc[ns-2],hullc[ns-1],hullc[0]))
		ns--;
	return ns;
}
int convex_hull_rob(int n)
{
	int i=2,ns=2;
	hullr[0].x=p[0].x;
	hullr[0].y=p[0].y;
	hullr[1].x=p[1].x;
	hullr[1].y=p[1].y;
	while(on_line(p[0],p[1],p[i]))
	{
		hullr[i].x=p[i].x;
		hullr[i].y=p[i].y;
		i++;
		ns++;
		if(i==n)
			return ns;
	}
    for(i=2;i<n;i++)
	{
		while(ns>=2)
		{
			if(right_turn(hullr[ns-2],hullr[ns-1],p[i]))
				ns--;
			else break;
		}
		hullr[ns].x=p[i].x;
		hullr[ns].y=p[i].y;
		ns++;
	}
	while(ns>=4 && right_turn(hullr[ns-2],hullr[ns-1],hullr[0]))
		ns--;
	return ns;
}
bool insidecop(double x,double y,int n)
{
	int i;
	double sum=0.,minx=inf,miny=inf,maxx=-inf,maxy=-inf;
	if(n<=2)return false;
	for(i=0;i<n;i++)
	{
		sum+=myabs(triarea(hullc[i].x,hullc[i].y,hullc[(i+1)%n].x,hullc[(i+1)%n].y,x,y));
		if(hullc[i].x<minx)minx=hullc[i].x;
		if(hullc[i].y<miny)miny=hullc[i].y;
		if(hullc[i].x>maxx)maxx=hullc[i].x;
		if(hullc[i].y>maxy)maxy=hullc[i].y;
	}
	if(minx>x || miny>y || maxx<x ||maxy<y)return false;
	if(myabs(sum-coparea)<eps)return true;
	else return false;
}
bool insiderob(double x,double y,int n)
{
	int i;
	double sum=0.,minx=inf,miny=inf,maxx=-inf,maxy=-inf;
	if(n<=2)return false;
	for(i=0;i<n;i++)
	{
		sum+=myabs(triarea(hullr[i].x,hullr[i].y,hullr[(i+1)%n].x,hullr[(i+1)%n].y,x,y));
		if(hullr[i].x<minx)minx=hullr[i].x;
		if(hullr[i].y<miny)miny=hullr[i].y;
		if(hullr[i].x>maxx)maxx=hullr[i].x;
		if(hullr[i].y>maxy)maxy=hullr[i].y;
	}
	if(minx>x || miny>y || maxx<x ||maxy<y)return false;
	if(myabs(sum-robarea)<eps)return true;
	else return false;
}
int main()
{
	int c,r,o,i,start,j,numc,numr,cs=0;
	double x,y;
	while(scanf("%d%d%d",&c,&r,&o)==3)
	{
		if(!c && !r && !o)break;
		p=(point *)calloc(c,sizeof(point));
		hullc=(point *)calloc(c,sizeof(point));
		for(i=0;i<c;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		start=findstart(c);
		for(j=0;j<c;j++)
		{
			p[j].dist=sqrt((p[j].x-p[start].x)*(p[j].x-p[start].x)+(p[j].y-p[start].y)*(p[j].y-p[start].y));
			if(j!=start)p[j].angle=getangle(p[j].x-p[start].x,p[j].y-p[start].y);
			else p[j].angle=0.0;
		}
		sort(p,p+c);
		if(c>=3)numc=convex_hull_cop(c);
		else numc=c;
		free(p);
		p=(point *)calloc(r,sizeof(point));
		hullr=(point *)calloc(r,sizeof(point));
		for(i=0;i<r;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		start=findstart(r);
		for(j=0;j<r;j++)
		{
			p[j].dist=sqrt((p[j].x-p[start].x)*(p[j].x-p[start].x)+(p[j].y-p[start].y)*(p[j].y-p[start].y));
			if(j!=start)p[j].angle=getangle(p[j].x-p[start].x,p[j].y-p[start].y);
			else p[j].angle=0.0;
		}
		sort(p,p+r);
		if(r>=3)numr=convex_hull_rob(r);
		else numr=r;
		free(p);
		for(j=coparea=0;j<numc;j++)
			coparea+=(hullc[j].x*hullc[(j+1)%numc].y);
		for(j=0;j<numc;j++)
			coparea-=(hullc[j].y*hullc[(j+1)%numc].x);
		coparea*=0.5;
		for(j=robarea=0;j<numr;j++)
			robarea+=(hullr[j].x*hullr[(j+1)%numr].y);
		for(j=0;j<numr;j++)
			robarea-=(hullr[j].y*hullr[(j+1)%numr].x);
		robarea*=0.5;
		printf("Data set %d:\n",++cs);
		for(i=0;i<o;i++)
		{
			scanf("%lf%lf",&x,&y);
			if(insidecop(x,y,numc))printf("     Citizen at (%.0lf,%.0lf) is safe.\n",x,y);
			else if(insiderob(x,y,numr))printf("     Citizen at (%.0lf,%.0lf) is robbed.\n",x,y);
			else printf("     Citizen at (%.0lf,%.0lf) is neither.\n",x,y);
		}
		printf("\n");
		free(hullc);
		free(hullr);
	}
	return 0;
}













