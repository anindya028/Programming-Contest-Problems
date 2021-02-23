#include<stdio.h>
#include<math.h>

int main()
{
	int t;
	scanf("%d",&t);
	double a,b,s;
	while(t--)
	{
		scanf("%lf%lf%lf",&a,&b,&s);
		if((s/b)<1e-8)
		{
			printf("100.000000%%\n");
			continue;
		}
		if(a*b<s)
		{
			printf("0.000000%%\n");
			continue;
		}
		double ans = s* (log(a)-log(s/b)) + s;
		ans = (a*b - ans)/(a*b);
		printf("%.6lf%%\n",ans*100);
	}
	return 0;
}
