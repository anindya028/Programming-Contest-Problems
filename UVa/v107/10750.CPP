#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 100000000.
#define eps 1e-8
#define myabs(a) ((a>0)?(a):-(a))
struct point
{
	double x,y;
}p[10005];
bool operator<(point a,point b)
{
	if(myabs(a.x-b.x)<eps)
		return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	int i,n,j,t,k;
	double x1,x2,y1,y2,dist,min;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		if(k)
			printf("\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p,p+n);
		min=inf;
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				if((p[j].x-p[i].x)>=min)break;
				if(myabs(p[j].x-p[i].x)<eps)
				{
					if((p[j].y-p[i].y)>=min)break;
				}
				dist=sqrt((p[j].x-p[i].x)*(p[j].x-p[i].x)+(p[j].y-p[i].y)*(p[j].y-p[i].y));
				if(dist<min)
				{
					min=dist;
					x1=p[i].x;
					x2=p[j].x;
					y1=p[i].y;
					y2=p[j].y;
				}
			}
		printf("%.3lf %.3lf\n",(x1+x2)/2.,(y1+y2)/2.);
	}
	return 0;
}













