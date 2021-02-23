//Closest Pair
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64 
#define inf 10000000
#define eps 1e-8
#define myabs(a) ((a>0)?(a):-(a))
#define Long long long

struct point
{
	Long x,y;
}p[100005];


bool operator<(point a,point b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

Long sqr(Long n){
	return n*n;
}
int main()
{
	int n,i,j;
	Long x1,y1,x2,y2,dist,mn;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%lld%lld",&p[i].x,&p[i].y);
		sort(p,p+n);
		mn=inf;
		mn*=mn;
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				if((p[j].x-p[i].x)>=mn)
					break;
				if(p[j].x==p[i].x)
				{
					if((p[j].y-p[i].y)>=mn)
						break;
				}
				dist=sqrt(sqr(p[j].x-p[i].x)+sqr(p[j].y-p[i].y));
				if(dist<mn)
				{
					mn=dist;
					x1=p[i].x;
					x2=p[j].x;
					y1=p[i].y;
					y2=p[j].y;
				}
			}
		if(myabs(y2-y1)>myabs(x2-x1))
			printf("%lld\n",myabs(y2-y1));
		else
			printf("%lld\n",myabs(x2-x1));
	}

	return 0;
}