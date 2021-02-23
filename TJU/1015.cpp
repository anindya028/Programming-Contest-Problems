#include<stdio.h>
#include<math.h>

int main()
{
	int m,n,t,cs;
	double ans;
	scanf("%d",&t);
	for(cs=0;cs<t;++cs)
	{
		scanf("%d%d",&m,&n);
		printf("Scenario #%d:\n",cs+1);
		if(n%2==0 || m%2==0)
			ans=n*m;
		else
			ans=n*m+sqrt(2.0)-1;
		printf("%.2lf\n\n",ans);
	}
	return 0;
}