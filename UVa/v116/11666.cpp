#include<stdio.h>
#include<math.h>

#define eps 1e-9
#define mabs(a) (((a)>0)?(a):-(a))
#define E(a,b) (mabs((a)-(b))<eps)

int main()
{
	int n,i;
	double e=exp(1.0);
	while(scanf("%d",&n)==1 && n)
	{
		int l=1;
		double lo;
		while(exp(l+0.0)<n)
			l++;
		int ans;
		for(i=l-2;i<=l+2;i++)
		{
			lo=1-n/exp(i+0.0);
			if(mabs(lo)<1)
			{
				ans=i;
				break;
			}
		}
		printf("%d %.8lf\n",ans,lo);
	}
	return 0;
}