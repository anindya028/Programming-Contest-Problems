/*this is my code-wa,wa,wa,wa....->all samples satisfied
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define Long __int64
//#define Long long long
#define Max 120
#define pye (2.*acos(0.0))
#define eps 1e-10
#define getc(x1,x2,x3) ((x1+x2+x3)/3.)
struct point
{
	Long x,y;
	double ang;
}p[Max];
double cx,cy;
Long trarea(Long x1,Long y1,Long x2,Long y2,Long x3,Long y3) 
{
	return ((x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1));
}
Long myabs(Long a)
{
	return (a>0)?(a):(-a);
}
double getangle(Long dx,Long dy)
{
	if(dx==0)
	{
		if(dy>0)return pye/2;
		else return 3.*pye/2;
	}
	else if(dy==0)
	{
		if(dx>0)return 0;
		else return pye;
	}
	if(atan2(dy,dx)<0)return atan2(dy,dx)+2.*pye;
	return atan2(dy,dx);
}
int findstart(int n)
{
	int i,k=0;
	Long miny=p[k].y;
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
	if(a.ang<b.ang)return 1;
	else return 0;
}
void find_centre_of_gravity(int n)
{
	int i;
	Long area,totalarea;
	double cx1,cy1,d,a;
	totalarea=myabs(trarea(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y));
	cx=getc(p[0].x,p[1].x,p[2].x);
	cy=getc(p[0].y,p[1].y,p[2].y);
	for(i=2;i<(n-1);i++)
	{
		area=myabs(trarea(p[0].x,p[0].y,p[i].x,p[i].y,p[i+1].x,p[i+1].y));
		cx1=getc(p[0].x,p[i].x,p[i+1].x);
		cy1=getc(p[0].y,p[i].y,p[i+1].y);
		d=sqrt((cx-cx1)*(cx-cx1)+(cy-cy1)*(cy-cy1));
		if(d>eps)
		{
			a=(area*d)/(totalarea+area);
			cx=cx+(cx1-cx)*a/d;
			cy=cy+(cy1-cy)*a/d;	
		}
		totalarea+=area;
	}
	return;
}
int main()
{
	int n,i,k;
	while(scanf("%d",&n)==1)
	{
		if(n<3)break;
		for(i=0;i<n;i++)
		{
			scanf("%I64d%I64d",&p[i].x,&p[i].y);
		}
		k=findstart(n);
		for(i=0;i<n;i++)
		{
			if(i==k)p[i].ang=-1;
			else p[i].ang=getangle(p[i].x-p[k].x,p[i].y-p[k].y);
		}
		sort(p,p+n);
		find_centre_of_gravity(n);
		if(cx>(-.005) && cx<0.000)cx=0.0;
		if(cy>(-.005) && cy<0.000)cy=0.0;
		printf("%.3lf %.3lf\n",cx+eps,cy+eps);
	}
	return 0;
}
*/
//center of gravity
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Long __int64
//#define Long long long
#define Max_Vertex 120
#define Max_angle 12
#define PI (2.*acos(0.0))
#define Limit 1e-10
#define myabs(a) ((a>0)?(a):-(a))
#define dist(a,b,c,d) (sqrt((a-c)*(a-c)+(b-d)*(b-d)))
#define getcx(x1,x2,x3) ((x1+x2+x3)/3.)
#define getcy(y1,y2,y3) ((y1+y2+y3)/3.)
#define triarea(x1,y1,x2,y2,x3,y3) ((x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1))
int index[Max_Vertex];
double an[Max_Vertex];
Long x[Max_Vertex],y[Max_Vertex];

double getangle(Long dx,Long dy)
{
if(dx==0)
{
if(dy>0) return PI/2.;
else return 3.*PI/2;
}
else if(dy==0)
{
if(dx>0)return 0;
else return PI;
}
if(atan2(dy,dx)<0) return atan2(dy,dx)+2.*PI;
return atan2(dy,dx);
}
int sortp(const void *p,const void *q)
{
int a=*(int *)p,b=*(int *)q;
if(an[a]<an[b]) return -1;
else return 1;
}
Long findstartingpoint(int n,Long *x,Long *y)
{
int i,p=0;
Long miny=y[p];
for(i=0;i<n;i++)
{
if(y[i]==miny)
{
if(x[i]<x[p])
{
p=i;
}
}
else if(y[i]<miny)
{
miny=y[i];
p=i;
}
}
return p;
}

void findcent(int n,Long *x,Long *y,double *cx,double *cy)
{
int i;
Long area,totarea;
double cx1,cy1,a,d;
totarea=myabs(triarea(x[index[0]],y[index[0]],x[index[1]],y[index[1]],x[index[2]],y[index[2]]));
*cx=getcx(x[index[0]],x[index[1]],x[index[2]]);
*cy=getcy(y[index[0]],y[index[1]],y[index[2]]); 
for(i=2;i<=n-2;i++)
{
area=myabs(triarea(x[index[0]],y[index[0]],x[index[i]],y[index[i]],x[index[i+1]],y[index[i+1]]));
cx1=getcx(x[index[0]],x[index[i]],x[index[i+1]]);
cy1=getcy(y[index[0]],y[index[i]],y[index[i+1]]);
d=dist(*cx,*cy,cx1,cy1);
if(d>Limit)
{
a=(area*d)/(totarea+area);
*cx=*cx+(cx1-*cx)*a/d;
*cy=*cy+(cy1-*cy)*a/d;
}
totarea+=area;
}
return;
}
void  main()
{
int n,i,k;
double cx,cy;
while(scanf("%d",&n)==1 && n>=3)
{
for(i=0;i<n;i++)
{
scanf("%I64d%I64d",&x[i],&y[i]);
index[i]=i;
}
k=findstartingpoint(n,x,y);
for(i=0;i<n;i++)
{
if(i==k) an[i]=-1.;
else an[i]=getangle(x[i]-x[k],y[i]-y[k]);
}
qsort(index,n,sizeof(int),sortp);
findcent(n,x,y,&cx,&cy);
printf("%.3lf %.3lf\n",cx,cy);
}
return;
}











