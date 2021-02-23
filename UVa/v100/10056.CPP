//probability 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

int main()
{
	int t,n,s;
	double ans,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lf%d",&n,&p,&s);
		if(p<1e-8)
		{
			ans=0.;
			printf("%.4lf\n",ans);
			continue;
		}
		ans=p*pow((1-p),(double)(s-1));
		ans/=(1-pow((1-p),(double)(n)));
		printf("%.4lf\n",ans);
	}
	return 0;
}
