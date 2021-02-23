#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	double l,f;
	while(scanf("%lf%lf",&l,&f)==2 &&l)printf("%.8lf %.8lf\n",sqrt(l*f*2),(sqrt(l*f*2)*3600)/(2*l));
	return 0;
}













