#include<stdio.h>
#include<math.h>

#define eps 1e-7
#define myabs(a) ((a)>0 ? (a) : -(a))
bool iseq(double a,double b){return (myabs(a-b))<eps;}
#define pye 2.*acos(0.0)
#define sq(a) ((a)*(a))
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))

double myv;
int n,done[9];

struct point 
{
	double x,y;
}now,origin;

struct senior
{
	point pi;
	double ang,v,cosa,sina;
}s[9];

enum {FRONT=0,BEHIND,EXACT};

double dist(point a,point b)
{
	return sqrt(sq(a.x-b.x)+sq(a.y-b.y));	
}

int intersect(double t,senior sn,double gone)
{
	double r=myv*(t-gone);
	point k;
	k.x=sn.pi.x+sn.cosa*t;
	k.y=sn.pi.y+sn.sina*t;
	double d=dist(k,now);
	if(iseq(d,r))
	{
		now=k;
		return EXACT;
	}
	else if(d>r)
		return BEHIND;
	else
		return FRONT;
}	

double binsearch(int k,double gone)
{
	double low=gone,high=gone+1000,mid;
	while(high-low>1e-2)
	{
		mid=low+(high-low)/2;
		int g=intersect(mid,s[k],gone);
		if(g==EXACT)
			return mid;
		else if(g==BEHIND)
			low=mid+eps;
		else
			high=mid-eps;
	}
	point kp;
	kp.x=s[k].pi.x+s[k].cosa*low;
	kp.y=s[k].pi.y+s[k].sina*low;
	now=kp;
	return low;
}

double process(int lev,double gone)
{
	int i;
	double ret=10000000.,k,j,tt;
	point temp;
	if(lev==n)
		return 0.;
	for(i=0;i<n;i++)
		if(!done[i])
		{
			done[i]=1;
			temp=now;
			k=binsearch(i,gone);
			tt=dist(now,origin)/s[i].v;
			j=process(lev+1,k);
			ret=Min(ret,k-gone+Max(tt,j));
			done[i]=0;
			now=temp;
		}
	return ret;
}

int main()
{
	int i;
	double ans;
	while(scanf("%d",&n)==1 && n)
	{
		scanf("%lf",&myv);
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf%lf",&s[i].pi.x,&s[i].pi.y,&s[i].v,&s[i].ang),
									s[i].cosa=s[i].v*cos(s[i].ang),
									s[i].sina=s[i].v*sin(s[i].ang);
		for(i=0;i<n;i++)
			done[i]=0;
		now.x=now.y=origin.x=origin.y=0;
		ans=process(0,0);
		printf("%.0lf\n",ans+eps);
	}
	return 0;
}
