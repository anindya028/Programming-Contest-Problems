#include<stdio.h>

#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,(a))

int num[100005];

int main()
{
	register int i,j;
	int cnt[5205],sum,low,hi,n,ans,mx,tem;
	while(scanf("%d%d%d",&n,&low,&hi)==3)
	{
		Foro(i,n)
			scanf("%d",&num[i]);
		mx=-1,ans=low;
		For(j,low,hi+1)
		{
			Foro(i,j+1)
				cnt[i]=0;
			cnt[0]=1;
			sum=tem=0;
			Foro(i,n)
				sum=(sum+num[i])%j,tem+=cnt[sum],cnt[sum]++;
			if(tem>mx)
				mx=tem,ans=j;
		}
		printf("%d\n",ans);
	}
	return 0;
}