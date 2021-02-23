#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
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

struct point
{
	double x,y;
}p[105];

bool operator<(point a,point b)
{
	return a.x>b.x;
}

double calc(point a,point b,double Y)
{
	return (a.x+(Y-a.y)*(a.x-b.x)/(a.y-b.y));
}

int main()
{
	int cs,t,n,i;
	double sum,now,dx,dy;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d",&n);
		sum=0;
		Foro(i,n)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p,p+n);
		sum+=sqrt(sq(p[1].y-p[0].y)+sq(p[1].x-p[0].x));
		now=p[1].y;
		for(i=2;i<n;i++)
		{
			if(p[i].y<now)
				continue;
			dy=p[i].y-now;
			dx=p[i].x-calc(p[i],p[i-1],now);
			sum+=sqrt(sq(dx)+sq(dy));
			now=p[i].y;
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}
