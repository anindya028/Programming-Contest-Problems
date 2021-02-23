#include<stdio.h>

#define sq(a) ((a)*(a))
#define myabs(a) (((a)>0)?(a):-(a))
#define eps 1e-10
#define Max(a,b) (((a)>(b))?(a):(b))

double t;

double make(int n,double a)
{
	double now,b,c=0;
	if(!n)
		return a;
	now=make(n-1,2*a);
	b=a/now;
	if(b>t)
		c+=((b-t)*a);
	c+=((1-sq(Max(b,t)))*now/2);
	return c/(1-t);
}

int main()
{
	int n,i;
	double two[31];
	two[0]=1;
	for(i=1;i<31;i++)
		two[i]=two[i-1]*2.;
	while(scanf("%d%lf",&n,&t)==2 && n)
	{
		if(t==1)
		{
			printf("%.3lf\n",two[n]);
			continue;
		}
		printf("%.3lf\n",make(n,1));
	}
	return 0; 
}