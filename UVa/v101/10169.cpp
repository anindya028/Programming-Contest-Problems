#include<stdio.h>
#include<math.h>

double p[1000000];
int z[1000000];

int main()
{
	int i,n;
	p[0]=0.0,z[0]=0;
	double temp=1.;
	for(i=1;i<1000000;i++)
	{
		temp*=((1./(i))/(i+1));
		p[i]=p[i-1]+(1./(i))/(i+1)*(1-p[i-1]);
		z[i]=z[i-1];
		while(temp<.1)
			temp*=10,z[i]++;
	}
	while(scanf("%d",&n)==1)
		printf("%lf %d\n",p[n],z[n]);
	return 0;
}