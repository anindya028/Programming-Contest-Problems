#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define pye 2.*acos(0.0)
#define eps 1e-9
#define mabs(a) (((a)>0)?(a):-(a))
#define E(a,b) (mabs(a-b)<eps)
#define Z(a) E(a,0)
#define sq(a) ((a)*(a))
#define Max(a,b) ((a)>(b)?(a):(b))

struct point
{
	double x,y,ang,d;
	int xx,yy;
}p[100005];

double getangle(double dx,double dy)
{
	if(Z(dx))
		return (dy>0?pye/2:3.*pye/2);
	if(Z(dy))
		return (dx>0?0.:pye);
	if(dy<0)
		return atan2(dy,dx)+2*pye;
	return atan2(dy,dx);
}

double lar;

bool operator<(point a,point b)
{
	if(E(a.ang,b.ang))
	{
		if(E(a.ang,lar))
			return a.d>b.d;
		return a.d<b.d;
	}
	return a.ang<b.ang;
}

int main()
{
	int n,i,t,j,k;
	char s[5];
//	freopen("D2.in","r",stdin);
//	freopen("D2.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=j=0;i<n;i++)
		{
			scanf("%d%d%s",&p[j].xx,&p[j].yy,s);
			p[j].x=p[j].xx,p[j].y=p[j].yy;
			if(s[0]=='Y')
				j++;
		}
		n=j;
		if(!n)
		{
			printf("0\n");
			continue;
		}
		k=0;
		for(i=1;i<n;i++)
			if(p[i].yy<p[k].yy)
				k=i;
			else if(p[i].yy==p[k].yy && p[i].xx<p[k].xx)
				k=i;
		lar=0;
		for(i=0;i<n;i++)
		{
			if(i==k)
			{
				p[i].ang=p[i].d=0.;
				continue;
			}
			p[i].ang=getangle(p[i].x-p[k].x,p[i].y-p[k].y);
			p[i].d=hypot(p[i].x-p[k].x,p[i].y-p[k].y);
			lar=Max(lar,p[i].ang);
		}
		sort(p,p+n);
		k=0;
		for(i=1;i<n;i++)
			if(p[i].xx<p[k].xx)
				k=i;
			else if(p[i].xx==p[k].xx && p[i].yy<p[k].yy)
				k=i;

		printf("%d\n",n);
		printf("%d %d\n",p[k].xx,p[k].yy);
		i=(k+1)%n;
		while(1)
		{
			if(i==k)
				break;
			printf("%d %d\n",p[i].xx,p[i].yy);
			i=(i+1)%n;
		}
	}
	return 0;
}

