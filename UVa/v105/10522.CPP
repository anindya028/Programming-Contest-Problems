#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
int main()
{
	double h,ha,hb,hc,a,x,y,z,t;
	int n;
	scanf("%d",&n);
	while(n)
	{
		scanf("%lf%lf%lf",&ha,&hb,&hc);
		//h=(ha+hb+hc)/2.0;
		if(ha<=0||hb<=0||hc<=0)
                {
				printf("These are invalid inputs!\n");
				n--;
				continue;
		}
		if((1/ha+1/hb)<=(1/hc)||(1/hb+1/hc)<=(1/ha)||(1/hc+1/ha)<=(1/hb))
		{
				printf("These are invalid inputs!\n");
				n--;
				continue;
		}
		t=1.0/ha+1.0/hb+1.0/hc;
		x=1.0/ha+1.0/hb-1.0/hc;
		y=1.0/ha-1.0/hb+1.0/hc;
		z=-1.0/ha+1.0/hb+1.0/hc;
		a=1.0/sqrt(x*y*z*t);
		printf("%.3lf\n",a);
        }
	return 0;
}













