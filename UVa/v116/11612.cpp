#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define mabs(a) (((a)>0)?(a):-(a))
#define eps 1e-9
#define sq(a) ((a)*(a))
#define pye (2.*acos(0.0))
#define iseq(a,b) (mabs(a-b)<eps)

struct point
{
	double x,y,angle,dist;
	int ind;
}p[1005];
double large;

double getangle(double dx,double dy)
{
	if(iseq(dx,0))
	{
		if(dy>0.)
			return pye/2;
		else if(iseq(dx,0))
			return 0;
		else
			return 3.*pye/2;
	}
	else if(iseq(dy,0.))
	{
		if(dx>0.)
			return 0.0;
		else
			return pye;
	}
	if(atan2(dy,dx)<0.) return atan2(dy,dx)+2.*pye;
	return atan2(dy,dx);
}

int findstart(int n)
{
	int i,k=0;
	double miny=p[k].y;
	for(i=1;i<n;i++)
		if(p[i].y==miny)
		{
			if(p[i].x<p[k].x)
				k=i;
		}
		else if(p[i].y<miny)
			miny=p[i].y,k=i;
	return k;
}

bool operator< (point a,point b)
{
	if(iseq(a.angle,b.angle))
	{
		if(iseq(a.angle,large))
			return a.dist>b.dist;
		return a.dist<b.dist;
	}
	return a.angle<b.angle;
}

int main()
{
	int n,i,j;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y),p[i].ind=i;
		j=findstart(n);
		large=-10000.;
		int cnt=1;
		for(i=0;i<n;i++)
		{
			p[i].angle=getangle(p[i].x-p[j].x,p[i].y-p[j].y),
			p[i].dist=sqrt(sq(p[i].x-p[j].x)+sq(p[i].y-p[j].y));
			if(p[i].angle>large)
				large=p[i].angle;
		}
		sort(p,p+n);
		for(i=2;i<n;i++)
			cnt+=(!iseq(p[i].angle,p[i-1].angle));
		if(cnt==1)
		{
			printf("no solution\n");
			continue;
		}
		i=0;
		while(p[i].ind)
			i++;
		printf("%d",p[i].ind);
		i=(i+1)%n;
		while(p[i].ind)
			printf(" %d",p[i].ind),i=(i+1)%n;
		printf(" 0\n");
	}
	return 0;
}
