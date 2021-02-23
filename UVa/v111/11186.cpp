#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define pye 2.*acos(0.0)

struct point 
{
	double x,y;
}p[505];

int main()
{
	int n,i,j;
	double r,ang[505],sx[505],sy[505];
	while(scanf("%d%lf",&n,&r)==2 && r>0)
	{
		if(!n)
		{
			printf("0\n");
			continue;
		}
		for(i=0;i<n;i++)
			scanf("%lf",&ang[i]);
		sort(ang,ang+n);
		for(i=0;i<n;i++)
			ang[i]=(ang[i]*pye)/180.0,
			p[i+1].x=r*cos(ang[i]),p[i+1].y=r*sin(ang[i]);
		sx[n]=p[n].x,sy[n]=p[n].y;
		double ans=0.0;
		for(i=n-1;i;i--)
			sx[i]=p[i].x+sx[i+1],
			sy[i]=p[i].y+sy[i+1];
		for(i=1;i<n;i++)
			for(j=i+1;j<n;j++)
				ans+=( p[i].x*(n-j)*p[j].y + p[j].x*sy[j+1] + p[i].y*sx[j+1] ),
				ans-=( p[i].y*(n-j)*p[j].x + p[j].y*sx[j+1] + p[i].x*sy[j+1] );
		ans/=2.0;
	/*	if(ans<0)
			ans*=(-1.0);*/
		printf("%.0lf\n",ans);
	}
	return 0;
}