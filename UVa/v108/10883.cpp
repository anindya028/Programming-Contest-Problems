#include<stdio.h>

double num[50005];

int main()
{
	int i,n,t,cs,j;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",&num[i]);
		double sum=num[0],now=1.;
		j=n-1;
		for(i=1;i<n;i++)
		{
			now*=n-i;
			now/=i;
			
			while(j && now>1.)
				sum/=2,now/=2,j--;
			sum+=now*num[i];
		}
		while(j)
			sum/=2.,j--;
		printf("Case #%d: %.3lf\n",cs+1,sum);
	}
	return 0;
}