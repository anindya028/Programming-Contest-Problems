//Very Easy Math
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int a1,b1,c1,a2,b2,c2;
	double x,y;
	while(scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2)==6)
	{
		if(!a1 && !b1 && !c1 && !a2 && !b2 && !c2)break;
		if((a1*b2)==(b1*a2))
		{
			printf("No fixed point exists.\n");
			continue;
		}
		if((c1*b2)!=(b1*c2))x=(double)(c1*b2-b1*c2)/(double)(a1*b2-b1*a2);
                else x=0.0;
		if((a1*c2)!=(a2*c1))y=(double)(a1*c2-a2*c1)/(double)(a1*b2-b1*a2);
		else y=0.0;
		printf("The fixed point is at %.2lf %.2lf.\n",x,y);
	}
	return 0;
}













