#include<stdio.h>
#include<math.h>

int main()
{
	int t;
	long long n,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=0;
		if(n<=0)
		{
			printf("0\n");
			continue;
		}
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		for(i=1;i*i<=n;i++)
		{
			if((i*i)==n || ((i+1)*(i+1)>n && (n<(i)*(i+1))))
			{
				ans+=(n/i);
				continue;
			}
			ans=ans + (n/i) + (n/i - n/(i+1) )*i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}