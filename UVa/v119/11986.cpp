#include<stdio.h>

#define LL long long

int main()
{
	int cs,T;
	LL n;
	scanf("%d",&T);
	for(cs = 1; cs <= T; cs++)
	{
		scanf("%lld",&n);
		int ans = 0;
		while(n)
		{
			ans++;
			n/=2;
		}
		printf("Case %d: %d\n",cs,ans);
	}
	return 0;
}