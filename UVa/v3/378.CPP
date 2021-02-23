#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,i;
	double x1,x2,x3,x4,y1,y2,y3,y4,m1,m2,c1,c2,x,y;
	printf("INTERSECTING LINES OUTPUT\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if(fabs(x1-x2)<1e-12)
		{
			x=x1;
			if(fabs(x3-x4)<1e-12)
			{
				if(fabs(x1-x3)<1e-12)
					printf("LINE\n");
				else printf("NONE\n");
				continue;
			}
			m2=(y3-y4)/(x3-x4);
			c2=-x3*m2+y3;
			y=m2*x+c2;
			printf("POINT %.2lf %.2lf\n",x,y);
			continue;
		}
		m1=(y1-y2)/(x1-x2);
		c1=-x1*m1+y1;
		if(fabs(x3-x4)<1e-12)
		{
			x=x3;
			y=m1*x+c1;
			printf("POINT %.2lf %.2lf\n",x,y);
			continue;
		}		
		m2=(y3-y4)/(x3-x4);
		c2=-x3*m2+y3;
		if(fabs(m1-m2)<1e-12)
		{
			if(fabs(c1-c2)<1e-12)printf("LINE\n");
			else printf("NONE\n");
		}
		else
		{
			x=(c1-c2)/(m2-m1);
			y=(m2*c1-m1*c2)/(m2-m1);
			printf("POINT %.2lf %.2lf\n",x,y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}













