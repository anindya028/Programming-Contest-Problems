#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

struct point
{
	double x,y,z;
}f[200],s[200],p;

double dist(double x,double y,double z)
{
	return x*x+y*y+z*z;
}

int main()
{
	int n,m,flag,cnt;
	register int i,j;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n && !m)
			break;
		for(i=0;i<n;++i)
			scanf("%lf%lf%lf",&f[i].x,&f[i].y,&f[i].z);
		for(i=0;i<m;++i)
			scanf("%lf%lf%lf",&s[i].x,&s[i].y,&s[i].z);
		for(i=cnt=0;i<m;++i)
		{
			for(j=0;j<n;++j)
			{
				double d1=dist(s[i].x,s[i].y,s[i].z);
				double d2=dist(s[i].x-f[j].x,s[i].y-f[j].y,s[i].z-f[j].z);
				double d3=dist(f[j].x,f[j].y,f[j].z);
				if(d1+d2<d3 || fabs(d1+d2-d3)<1e-8)
				{
					cnt++;
					break;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
