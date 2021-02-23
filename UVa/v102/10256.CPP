//Convex hull
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 10000000.
#define pye (2.*acos(0.))
#define eps 1e-12
#define myabs(a) ((a>0)?(a):-(a))
struct point
{
	double x,y,angle,dist;
}*p,*hullm,*hullc;
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
int convex_hullm(int n)
{
	int i=2,ns=2;
	hullm[0].x=p[0].x;
	hullm[0].y=p[0].y;
	hullm[1].x=p[1].x;
	hullm[1].y=p[1].y;
	if(n==2)
		return ns;
	while(on_line(p[0],p[1],p[i]))
	{
		i++;
		if(i==n)
		{
			hullm[1].x=p[n-1].x;
			hullm[1].y=p[n-1].y;
			return ns;
		}
	}
    for(i=2;i<n;i++)
	{
		while(ns>=2)
		{
			if(right_turn(hullm[ns-2],hullm[ns-1],p[i]))
				ns--;
			else break;
		}
		hullm[ns].x=p[i].x;
		hullm[ns].y=p[i].y;
		ns++;
	}
	while(ns>=4 && right_turn(hullm[ns-2],hullm[ns-1],hullm[0]))
		ns--;
	return ns;
}
int convex_hullc(int n)
{
	int i=2,ns=2;
	hullc[0].x=p[0].x;
	hullc[0].y=p[0].y;
	hullc[1].x=p[1].x;
	hullc[1].y=p[1].y;
	if(n==2)
		return ns;
	while(on_line(p[0],p[1],p[i]))
	{
		i++;
		if(i==n)
		{
			hullc[1].x=p[n-1].x;
			hullc[1].y=p[n-1].y;
			return ns;
		}
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
bool interdivide(point a,point b,point c)
{
	if((c.x>a.x && c.x<b.x) || (c.x<a.x && c.x>b.x))
		return true;
	return false;
}
bool samepoint(point a,point b)
{
	if(myabs(a.x-b.x)<eps && myabs(a.y-b.y)<eps)
		return true;
	return false;
}
bool linseg_linseg(point a,point b,point c,point d)//checks whether AB & CD intersects or not
{
	double m1,m2;
	if(myabs(b.x-a.x)<eps)m1=inf;
	else m1=(b.y-a.y)/(b.x-a.x);
	if(myabs(d.x-c.x)<eps)m2=inf;
	else m2=(d.y-c.y)/(d.x-c.x);
	if(myabs(m1-m2)<eps)
	{
		if(myabs(triarea(a.x,a.y,b.x,b.y,c.x,c.y))>eps)
			return false;
		if(samepoint(a,c) || samepoint(a,d) || samepoint(b,c) || samepoint(b,d))
			return true;
		if(interdivide(a,b,c) || interdivide(a,b,d) || interdivide(c,d,a) || interdivide(c,d,b))
			return true;
		else return false;
	}
	else
	{
		if((right_turn(a,b,c) ^ right_turn(a,b,d)) && (right_turn(c,d,a) ^ right_turn(c,d,b)))
			return true;
		return false;
	}
}
bool edge_sect(int num_m,int num_c)
{
	int i,j;
	for(i=0;i<num_m;i++)
		for(j=0;j<num_c;j++)
			if(linseg_linseg(hullm[i],hullm[(i+1)%num_m],hullc[j],hullc[(j+1)%num_c]))
				return true;
	return false;
}
bool fully_inside(int num_m,int num_c)
{
	int i;
	double sum=0,area_m=0,area_c=0;
	for(i=0;i<num_m;i++)
		area_m+=(hullm[i].x*hullm[(i+1)%num_m].y);
	for(i=0;i<num_m;i++)
		area_m-=(hullm[i].y*hullm[(i+1)%num_m].x);
	area_m*=.5;
	for(i=0;i<num_c;i++)
		area_c+=(hullc[i].x*hullc[(i+1)%num_c].y);
	for(i=0;i<num_c;i++)
		area_c-=(hullc[i].y*hullc[(i+1)%num_c].x);
	area_c*=.5;
	if(area_m>area_c)
	{
		for(i=0;i<num_m;i++)
			sum+=myabs(triarea(hullm[i].x,hullm[i].y,hullm[(i+1)%num_m].x,hullm[(i+1)%num_m].y,hullc[0].x,hullc[0].y));
		if(myabs(sum-area_m)<eps)
			return true;
		else return false;
	}
	else
	{
		for(i=0;i<num_c;i++)
			sum+=myabs(triarea(hullc[i].x,hullc[i].y,hullc[(i+1)%num_c].x,hullc[(i+1)%num_c].y,hullm[0].x,hullm[0].y));
		if(myabs(sum-area_c)<eps)
			return true;
		else return false;
	}
}
int main()
{
	int m,c,i,start,num_m,num_c,x,y;
	while(scanf("%d%d",&m,&c)==2)
	{
		if(!m && !c)break;
		if(!m)
		{
			for(i=0;i<c;i++)
				scanf("%lf%lf",&x,&y);
			printf("Yes\n");
			continue;
		}
		if(!c)
		{
			for(i=0;i<m;i++)
				scanf("%lf%lf",&x,&y);
			printf("Yes\n");
			continue;
		}
		p=(point *)calloc(m,sizeof(point));
		hullm=(point *)calloc(m,sizeof(point));
		for(i=0;i<m;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		start=findstart(m);
		for(i=0;i<m;i++)
		{
			p[i].dist=sqrt((p[i].x-p[start].x)*(p[i].x-p[start].x)+(p[i].y-p[start].y)*(p[i].y-p[start].y));
			if(i!=start)p[i].angle=getangle(p[i].x-p[start].x,p[i].y-p[start].y);
			else p[i].angle=0.0;
		}
		sort(p,p+m);
		if(m>1)num_m=convex_hullm(m);
		else
		{
			hullm[0]=p[0];
			num_m=1;
		}
		free(p);
		p=(point *)calloc(c,sizeof(point));
		hullc=(point *)calloc(c,sizeof(point));
		for(i=0;i<c;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		start=findstart(c);
		for(i=0;i<c;i++)
		{
			p[i].dist=sqrt((p[i].x-p[start].x)*(p[i].x-p[start].x)+(p[i].y-p[start].y)*(p[i].y-p[start].y));
			if(i!=start)p[i].angle=getangle(p[i].x-p[start].x,p[i].y-p[start].y);
			else p[i].angle=0.0;
		}
		sort(p,p+c);
		if(c>1)num_c=convex_hullc(c);
		else
		{
			hullc[0]=p[0];
			num_c=1;
		}
		if(num_m==1 && num_c==1)
		{
			if(samepoint(hullm[0],hullc[0]))
				printf("No\n");
			else printf("Yes\n");
		}
		else if(num_m==1)
		{
			if(num_c>2)
			{
				if(fully_inside(num_m,num_c))
					printf("No\n");
				else printf("Yes\n");
			}
			else
			{
				if(myabs(triarea(hullc[0].x,hullc[0].y,hullc[1].x,hullc[1].y,hullm[0].x,hullm[0].y))<eps && interdivide(hullc[0],hullc[1],hullm[0]))
					printf("No\n");
				else printf("Yes\n");
			}
		}
		else if(num_c==1)
		{
			if(num_m>2)
			{
				if(fully_inside(num_m,num_c))
					printf("No\n");
				else printf("Yes\n");
			}
			else
			{
				if(myabs(triarea(hullm[0].x,hullm[0].y,hullm[1].x,hullm[1].y,hullc[0].x,hullc[0].y))<eps && interdivide(hullm[0],hullm[1],hullc[0]))
					printf("No\n");
				else printf("Yes\n");
			}
		}
		else if(num_m==2 && num_c==2)
		{
			if(linseg_linseg(hullm[0],hullm[1],hullc[0],hullc[1]))
				printf("No\n");
			else printf("Yes\n");
		}
		else if(edge_sect(num_m,num_c) || fully_inside(num_m,num_c))
			printf("No\n");
		else printf("Yes\n");
		free(p);
		free(hullm);
		free(hullc);
	}
	return 0;
}
