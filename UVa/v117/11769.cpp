#include<stdio.h>
#include<math.h>

#define sq(a) ((a)*(a))

struct point
{
	double x,y,z;
	point(double x0=0,double y0=0,double z0=0){x=x0,y=y0,z=z0;}
}p[50];

double value(point a)
{
	return sqrt(sq(a.x)+sq(a.y)+sq(a.z));
}

double dot(point a,point b)
{
	return (a.x*b.x+a.y*b.y+a.z*b.z);
}

point cross(point a,point b)
{
	point c;
	c.x = a.y*b.z-a.z*b.y;
	c.y = a.z*b.x-a.x*b.z;
	c.z = a.x*b.y-a.y*b.x;
	return c;
}

double box(point a,point b,point c)
{
	return dot(a,cross(b,c));
}

int main()
{
	int cs=0,n,i,j,k,l;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
		double ans=0.;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				for(k=j+1;k<n;k++)
				{
					point a(p[j].x-p[i].x,p[j].y-p[i].y,p[j].z-p[i].z),
						b(p[k].x-p[j].x,p[k].y-p[j].y,p[k].z-p[j].z);
					bool isp=0,isn=0;
					for(l=0;l<n;l++)
					{
						if(l==i || l==j || l==k)
							continue;
						point c(p[l].x-p[k].x,p[l].y-p[k].y,p[l].z-p[k].z);
						if(box(a,b,c)>0)
							isp=1;
						else
							isn=1;
					}
					if(isp ^ isn)
						ans+=(0.5 * value(cross(a,b)));
				}
		printf("Case %d: %.2lf\n",++cs,ans);
	}
	return 0;
}