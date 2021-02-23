//geometry easy
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define pye (2.0*acos(0.0))
typedef unsigned long int myint;
void main()
{
	long d,v;
	double ans;
	while(scanf("%ld%ld",&d,&v)==2)
	{
        	if(!d)break;
		ans=pow(((d*d*d)-v*6/pye),1/3.0);
		printf("%.03lf\n",ans);
	}
}













