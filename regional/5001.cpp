#include<stdio.h>

#define LL long long

LL ans[70];

int main()
{
	int n,i,cs=0;
	ans[1]=ans[2]=ans[3]=1;
	for(i=4;i<=61;i++)
		ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
	while(scanf("%d",&n)==1 && n)
		printf("Case %d: %lld\n",++cs,ans[n]);
	return 0;
}