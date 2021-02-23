#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define sq(a) ((a)*(a))
#define eps 1e-9
#define mabs(a) ((a)>0?(a):-(a))
#define E(a,b) (mabs(a-b)<eps)
#define Min(a,b) (((a)<(b))?(a):(b))

struct point 
{
	int x,y,v,l;
}p[20],pp[20],hull[20];

int findstart(int n)
{
	int i,k=0;
	int mny=p[k].y;
	for(i=1;i<n;i++)
		if(p[i].y==mny)
		{
			if(p[i].x<p[k].x)
				k=i;
		}
		else if(p[i].y<mny)
		{
			mny=p[i].y;
			k=i;
		}
	return k;
}

int dist2(point a,point b)
{
	return (sq(a.x-b.x)+sq(a.y-b.y));
}

double dist(point a,point b)
{
	return sqrt((double)(sq(a.x-b.x)+sq(a.y-b.y)));
}

int triarea(point a,point b,point c)
{
	return ((a.x-b.x)*(b.y-c.y) - (a.y-b.y)*(b.x-c.x));
}

bool right_turn(point a,point b,point c)
{
	return (triarea(a,b,c)<=0);
}

bool on_line(point a,point b,point c)
{
	return (triarea(a,b,c)==0);
}

point base;
bool operator<(point a,point b)
{
	if(on_line(base,a,b))
		return dist2(base,a)<dist2(base,b);
	return (triarea(base,a,b)>0);
}

double convex_hull(int n)	
{
	int i=2,ns=2;		//number of points in hull
	if(n<2)
	{
		hull[0]=p[0];
		return 0;
	}
	int idx=findstart(n);
	base=p[idx];
	swap(p[0],p[idx]);
	sort(p+1,p+n);
	hull[0]=p[0];
	hull[1]=p[1];

	for(i=2;i<n;i++)
	{
		while(ns>=2)
		{
			if(right_turn(hull[ns-2],hull[ns-1],p[i]))
				ns--;
			else
				break;
		}
		hull[ns]=p[i];
		ns++;
	}
	double sum=0;
	for(i=0;i<ns;i++)
		sum+=dist(hull[i],hull[(i+1)%ns]);
	return sum;
}

int main()
{
	int n,i,j,ans,now,mn,fi,cs=0;
	double sum,wood;
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		if(cs)
			printf("\n");
		for(i=0;i<n;i++)
			scanf("%d%d%d%d",&pp[i].x,&pp[i].y,&pp[i].v,&pp[i].l);
		ans=mn=1000000000;
		for(i=0;i<(1<<n);i++)
		{
			sum=0;
			now=0;
			int k=0;
			for(j=0;j<n;j++)
				if(i & 1<<j)
					p[k++]=pp[j];
				else
				{
					sum+=pp[j].l;
					now+=pp[j].v;
				}
			
			double got=convex_hull(k);

			if(got<sum || E(got,sum))
			{
				if(now<ans || (now==ans && k<mn))
				{
					ans=now;
					mn=k;
					fi=i;
					wood=sum-got;
				}
			}
		}
		//printf("The lost value is %d.\n",ans);
		printf("Forest %d\n",++cs);
		printf("Cut these trees:");
		for(j=0;j<n;j++)
			if(!(fi & 1<<j))
				printf(" %d",j+1);
		printf("\nExtra wood: %.2lf\n",wood);
	}
	return 0;
}