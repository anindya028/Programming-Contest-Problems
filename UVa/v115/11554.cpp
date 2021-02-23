#include<stdio.h>

#define  LL long long
LL ans[1000005];

int main()
{
	int n,i,lo,le,t;
	LL odd=0,even=0;
	ans[3]=0;
	lo=1,le=2;
	for(i=4;i<1000002;++i)
	{
		if(i%2)
			even+=le,le+=2,ans[i]=ans[i-1]+even;
		else
			odd+=lo,lo+=2,ans[i]=ans[i-1]+odd;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",ans[n]);
	}
	return 0;
}

