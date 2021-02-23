#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define abs(a) ((a>0)?(a):-(a))
//#define Long __int64
#define Long long long
struct point
{
	Long x,y;
}p[1005];
Long gcd(Long m,Long n)
{
	if(!m)return n;
	if(!n)return m;
	return gcd(n,(m%n));
}
int main()
{
	int n,i;
	Long a,b;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&p[i].x,&p[i].y);
		}
		for(i=a=0;i<n;i++)
			a+=(p[i].x*p[(i+1)%n].y);
		for(i=0;i<n;i++)
			a-=(p[i].y*p[(i+1)%n].x);
		a=abs(a);
		for(i=b=0;i<n;i++)
			b+=(gcd(abs(p[(i+1)%n].x-p[i].x),abs(p[(i+1)%n].y-p[i].y))+1);
		b-=n;
		printf("%lld\n",(a-b)/2+1);
	}
	return 0;
}













