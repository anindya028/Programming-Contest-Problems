#include<stdio.h>
#include<math.h>

#define eps 1e-7
#define mabs(a) ((a)>0?(a):-(a))
#define E(a,b) (mabs(a-b)<eps)

double L,t1,t2,k,H;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf",&L,&k,&t1,&t2,&H);
		if(E(H,L))
		{
			double A=t1,B=-(L+k*t1+k*t2),C=k*L;
			double x1=(-B+sqrt(B*B-4*A*C))/(2*A);	
			printf("%.6lf %.6lf\n",H,x1*t1);
		}
		else if(H<L)
			printf("%.6lf %.6lf\n",H,H);
		else
		{
			double A=t1,B=-(H+k*t1+k*t2),C=k*L;
			double x1=(-B+sqrt(B*B-4*A*C))/(2*A);
			
			printf("%.6lf %.6lf\n",x1*t1,x1*t1);
		}

	}
	return 0;
}
