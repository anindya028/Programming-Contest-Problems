#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	double ma,mb,mc,m,a;
	while(scanf("%lf%lf%lf",&ma,&mb,&mc)==3)
	{
		m=ma+mb+mc;
		if((m<=2*ma)||(m<=2*mb)||(m<=2*mc))
		{
			printf("-1.000\n");
			continue;
                }
		a=sqrt(m*(m-2*ma)*(m-2*mb)*(m-2*mc))/3.0;
		printf("%.3lf\n",a);
	}
	return 0;
}













