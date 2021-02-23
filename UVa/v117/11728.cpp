#include<stdio.h>

int main()
{
	int i,n,ans,j,sum,cs=0;
	while(scanf("%d",&n)==1 && n)
	{
		if(n==1)
		{
			printf("Case %d: %d\n",++cs,1);
			continue;
		}
		ans=-1;
		for(i=n-1;i>=2;i--)
		{
			sum=1+i;
			for(j=2;j*j<=i;j++)
				if(i%j==0)
					sum+=j,sum+=((j*j!=i)*(i/j));
			if(sum==n)
			{
				ans=i;
				break;
			}
		}
		printf("Case %d: %d\n",++cs,ans);
	}
	return 0;
}