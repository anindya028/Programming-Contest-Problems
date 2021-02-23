#include<stdio.h>

#define mabs(a) ((a)>0?(a):-(a))
#define LL long long
#define inf 2000000000

LL val[1005];

int main()
{
	int i,t,cs=0,n,m,k;
	LL sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(i=sum=0;i<n;i++)
		{
			scanf("%lld",&val[i]);
			sum+=val[i];
		}
		
		LL ans1 = inf;

		for(i=0;i<m;i++)
			if( mabs(val[i]*n-sum)<mabs(ans1*n-sum) || ( mabs(val[i]*n-sum)==mabs(ans1*n-sum) && val[i]<ans1))
				ans1 = val[i];

		printf("Case #%d: %lld",++cs,ans1);
		
		ans1 = inf;
		for(;i<m+k;i++)
			if( mabs(val[i]*n-sum)<mabs(ans1*n-sum) || ( mabs(val[i]*n-sum)==mabs(ans1*n-sum) && val[i]<ans1))
				ans1 = val[i];
		printf(" %lld\n",ans1);
	}
	return 0;
}