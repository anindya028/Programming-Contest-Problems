#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

#define eps 1e-8
#define mabs(a) (((a)>0)?(a):-(a))
#define E(a,b) (mabs(a-b)<eps)
#define Z(a) E(a,0)
#define Min(a,b) (((a)<(b))?(a):(b)) 
#define Max(a,b) (((a)>(b))?(a):(b))

struct point
{
	double x,y;
};

vector<point> poly[25];

bool inpoly(vector<point> polygon,point p)
{
	int i,counter=0,n=polygon.size();
	double xinters;
	point p1,p2;
	p1=polygon[0];
/*	for(i=0;i<n;i++)
		if(on_line(polygon[i],polygon[(i+1)%n],p) && interior(polygon[i],polygon[(i+1)%n],p))
			return (inside);
	if(n==2)
		return (outside);*/
	for(i=1;i<=n;i++)
	{
		p2=polygon[i%n];
		if(p.y>Min(p1.y,p2.y))
		{
			if((int)p.y<=(int)Max(p1.y,p2.y))
			{
				if(p.x<Max(p1.x,p2.x))
				{
					if(!E(p1.y,p2.y))
					{
						xinters=(p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
						if(E(p1.x,p2.x) || E(p.x,xinters) || p.x<xinters)
							counter++;
					}
				}
			}
		}
		p1=p2;
	}
	if(counter%2==0)return false;
	else  return true;
}

int main()
{
	int t,cs,n,q,i,j,m;
	point temp,so,de;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			poly[i].clear();
			for(j=0;j<m;j++)			
				scanf("%lf%lf",&temp.x,&temp.y),poly[i].push_back(temp);	
		}
		printf("Case %d:\n",cs+1);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%lf%lf%lf%lf",&so.x,&so.y,&de.x,&de.y);
			for(i=j=0;i<n;i++)
				if(inpoly(poly[i],so) ^ inpoly(poly[i],de))
					j++;
			printf("%d\n",j);
		}
	}
	return 0;
}