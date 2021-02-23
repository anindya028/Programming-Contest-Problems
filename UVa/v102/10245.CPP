//Closest Pair 
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 10000.
struct point
{
	double x,y;
}*p;
bool operator<(point a,point b)
{
	return a.x<b.x;
}
int main()
{
	int i,n,j;
	double min,dist;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		p=(point *)calloc(n,sizeof(point));
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p,p+n);
		min=inf;
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				if((p[j].x-p[i].x)>=min)break;
				dist=sqrt((p[j].x-p[i].x)*(p[j].x-p[i].x)+(p[j].y-p[i].y)*(p[j].y-p[i].y));
				if(dist<min)min=dist;
			}
		if(min<inf)printf("%.4lf\n",min);
		else printf("INFINITY\n");
		free(p);
	}
	return 0;
}













