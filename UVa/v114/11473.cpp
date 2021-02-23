#include<stdio.h>
#include<math.h>

#define eps 1e-9
#define mabs(a) (((a)>0)?(a):-(a))
#define iseq(a,b) (mabs(a-b)<eps)

struct point 
{
	double x,y;
}p[105];

inline double dist(point a,point b)
{
	return hypot(a.x-b.x,a.y-b.y);
}

int main()
{
	int t,n,m,i,cs,k;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		
		double tot=0;
		for(i=1;i<n;i++)
			tot+=dist(p[i],p[i-1]);
		double d=tot/(m-1);
		printf("Road #%d:\n",cs+1);
		printf("%.2lf %.2lf\n",p[0].x,p[0].y);
		point prev;
		prev.x=p[0].x,prev.y=p[0].y;
		k=1;
		for(i=1;i<m;i++)
		{
			double now=d;
			while(dist(prev,p[k])<now)
			{
				now-=dist(prev,p[k]);
				prev=p[k];
				k++;
			}
			double a=dist(p[k],prev),b=p[k].x-prev.x,c=p[k].y-prev.y; 
			prev.x+=(b/a)*now;
			prev.y+=(c/a)*now;
			printf("%.2lf %.2lf\n",prev.x,prev.y);
		}
		printf("\n");
	}
	return 0;
}
