#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define eps 1e-9
#define inf 100000000.
#define myabs(a) (((a)>0)?(a):-(a))

struct point
{
	int x,y;
	
}q[20005];
int n;

int main()
{
	int k;
	register int i,j;
	//double m,dish,disl,dism;
	point a,b;//low,high,mid;
	int dist[20005],sum,*freq,mid;
	int _a,_b,_c;
	while(scanf("%d%d",&n,&k)==2)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&q[i].x,&q[i].y);
		for(i=0;i<k;i++)
		{
			scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
			_b=a.x-b.x;
			_a=b.y-a.y;
			_c=-(_a*a.x+_b*a.y);
			for(j=0;j<n;j++)
				dist[j]=_a*q[j].x+_b*q[j].y+_c;
			sort(dist,dist+n);
			if(n%2)mid=dist[n/2];
			else mid=(dist[n/2]+dist[n/2-1])/2;
			for(j=sum=0;j<n;j++)
				sum+=myabs(dist[j]-mid);
			printf("Case %d: %.0lf\n",i+1,floor((sum/sqrt(_a*_a+_b*_b))+.5+eps));
			////********this was my first attempt of ternary seach->TLE
			///****mistake in code(less chance) or strict(!) time limit of the problem?
			/*if(myabs(a.x-b.x)<eps)m=inf;
			else m=(a.y-b.y)/(a.x-b.x);
			if(m<0)
			{
				low.ini(-101,-101);
				high.ini(101,101);
			}
			else
			{
				low.ini(101,-101);
				high.ini(-101,101);
			}
			dish=sum_of_dist(high,m);
			disl=sum_of_dist(low,m);
			while(dist(low,high)>1.)
			{
				mid.ini((low.x+high.x)/2.,(low.y+high.y)/2.);
				dism=sum_of_dist(mid,m);
				if(myabs(dism-disl)<myabs(dism-dish))
				{
					high=mid;
					dish=dism;
				}
				else if(myabs(dism-disl)>myabs(dism-dish))
				{
					low=mid;
					disl=dism;
				}
				else break;
			}
			printf("Case %d: %.0lf\n",i+1,floor(dism+.5+eps));*/
		}
	}
	return 0;
}













