#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#include<algorithm>
using namespace std;
struct point
{
	double x,y;
};
bool operator<(point a,point b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	point *p;
	int t,n,i,j,flag;
        double xmid,ymid;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		p=(point *)calloc(n,sizeof(point));
		for(j=0;j<n;j++)scanf("%lf%lf",&p[j].x,&p[j].y);
		if(n==2)
		{
			printf("yes\n");
			free(p);
			continue;
		}
                flag=1;
		sort(p,p+n);
		xmid=(p[0].x+p[n-1].x)/2;
		ymid=(p[0].y+p[n-1].y)/2;
		for(j=1;j<n/2;j++)
		{
			if((p[j].x+p[n-j-1].x)/2!=xmid)
			{
				flag=0;
				break;
			}
			if((p[j].y+p[n-j-1].y)/2!=ymid)
			{
				flag=0;
				break;
			}
		}
		if(n%2)
		{
			if(p[j].x!=xmid||p[j].y!=ymid)flag=0;
		}
		if(flag)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}













