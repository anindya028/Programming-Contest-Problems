#include<stdio.h>
#include<string.h>

int fr[1000005];
int num[50005],cum[50005];

int main()
{
	int n,i,d,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&d,&n);
		for(i=0;i<=d;i++)
			fr[i]=0;
		cum[0]=num[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			cum[i]=(cum[i-1]+num[i])%d;
			fr[cum[i]]++;
		}
		long long ans=0;
		for(i=1;i<=n;i++)
		{
			ans+=fr[cum[i-1]];
			fr[cum[i]]--;
		}
		printf("%lld\n",ans);
	}
	return 0;
}