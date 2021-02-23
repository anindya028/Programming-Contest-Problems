//AC
//checking a point within a convex polygon in O(log(n))

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define Long long long
#define size 100005
#define myabs(a) (((a)>0)?(a):-(a))

struct point
{
	Long x,y;
}poly[size],rock[size],rough[15];

inline Long triarea(point a,point b,point c)
{
	return ((a.x-b.x)*(b.y-c.y)-(a.y-b.y)*(b.x-c.x));
}

inline Long dist(point a,point b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline bool on_line(point a,point b,point c)
{
	if(triarea(a,b,c)==0)
		return true;
	else return false;
}

inline bool right_turn(point a,point b,point c)
{
	if(triarea(a,b,c)>0)
		return false;
	return true;
}

inline bool interdivide(point a,point b,point c)
{
	Long ac,cb,ab;
	ac=dist(a,c);
	cb=dist(c,b);
	ab=dist(a,b);
	return ((ac<=ab) && (cb<=ab));
}

bool inside(int start,int end,point p)
{
	int i,mid,j,n;
	Long sum,area;
	if((end-start)<10)
	{
		rough[0]=poly[0];
		for(i=1,j=start;j<=end;j++,i++)
			rough[i]=poly[j];
		n=i;
		area=0;
		for(i=0;i<n;i++)
			area+=rough[i].x*rough[(i+1)%n].y;
		for(i=0;i<n;i++)
			area-=rough[i].y*rough[(i+1)%n].x;
		area=myabs(area);
		sum=0;
		for(i=0;i<n;i++)
			sum+=myabs(triarea(rough[i],rough[(i+1)%n],p));
		if(sum==area)
			return true;
		else return false;
	}
	mid=(start+end)/2;
	if(on_line(poly[0],poly[mid],p))
	{
		if(interdivide(poly[0],poly[mid],p))
			return true;
		return false;
	}
	if(right_turn(poly[0],poly[mid],p))
		return inside(start,mid,p);
	else
		return inside(mid,end,p);
}

bool process(point p,int n)
{
	int i;
	Long area,sum;
	if(n<30)
	{
		area=0;
		for(i=0;i<n;i++)
			area+=poly[i].x*poly[(i+1)%n].y;
		for(i=0;i<n;i++)
			area-=poly[i].y*poly[(i+1)%n].x;
		area=myabs(area);
		sum=0;
		for(i=0;i<n;i++)
			sum+=myabs(triarea(poly[i],poly[(i+1)%n],p));
		if(sum==area)
			return true;
		else return false;
	}
	if(on_line(poly[0],poly[n/2],p))
	{
		if(interdivide(poly[0],poly[n/2],p))
			return true;
		return false;
	}
	if(right_turn(poly[0],poly[n/2],p))
	{
		if(on_line(poly[0],poly[1],p))
		{
			if(interdivide(poly[0],poly[1],p))
				return true;
			return false;
		}
		return inside(1,n/2,p);
	}
	else
	{
		if(on_line(poly[0],poly[n-1],p))
		{
			if(interdivide(poly[0],poly[n-1],p))
				return true;
			return false;
		}
		return inside(n/2,n-1,p);
	}
}
int main()
{
	int t,n,m,k,i,cnt;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld%lld",&poly[i].x,&poly[i].y);

		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%lld%lld",&rock[i].x,&rock[i].y);
		
		for(i=cnt=0;i<m;i++)
		{
			if(process(rock[i],n))
				printf("y\n");
			else
				printf("n\n");
		}
	}
	return 0;
}
