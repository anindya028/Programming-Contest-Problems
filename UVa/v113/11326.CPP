//Euclidean geometry
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define pye 2.*acos(0.0)
#define eps 1e-9
int main()
{
	double l,w,theta,n,a,b,c,d;
	int t,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&l,&w,&theta);
		if(theta<eps)
		{
			printf("1.000\n");
			continue;
		}
		theta=theta*pye/180.;
		n=l*tan(theta)/w;
		k=(int)n;
		c=l-k*w/tan(theta);
		d=c*tan(theta);
		a=k*w/sin(theta)+sqrt(c*c+d*d);
		if(k%2==0)b=sqrt(d*d+l*l);
		else b=sqrt((w-d)*(w-d)+l*l);
		printf("%.3lf\n",a/b);
	}
	return 0;
}













