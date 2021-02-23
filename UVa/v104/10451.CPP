//Euclidean Geometry
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define pye 2*acos(0.0) 
int main()
{
	double n,a,r,R;
        int cs=0;
	while(scanf("%lf%lf",&n,&a)==2 && n>=3)
	{
		r=sqrt(2*a/(n*sin(2*pye/n)));
		R=sqrt(a/(n*tan(pye/n)));
		printf("Case %d: %.5lf %.5lf\n",++cs,pye*r*r-a,a-pye*R*R);
	}
	return 0;
}













