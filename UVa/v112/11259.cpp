#include<stdio.h>

#define LL long long
#define MX 100000

LL ways[100005];

int main()
{
	int t,c[4],d[4],i,j,q,v,now,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&c[0],&c[1],&c[2],&c[3],&q);
		ways[0]=1;
		for(j=1;j<=MX;j++)
			ways[j]=0;
		for(i=0;i<4;i++)
			for(j=0;j<=MX;j++)
				if(j+c[i]<=MX)
					ways[j+c[i]]+=ways[j];

		while(q--)
		{
			for(i=0;i<4;i++)
				scanf("%d",&d[i]);
			scanf("%d",&v);
			LL ans=0;
			for(i=0;i<16;i++)
			{
				for(j=k=now=0;j<4;j++)
					if(i & (1<<j))
					{
						k++;
						now+=(c[j]*(d[j]+1));
					}
				if(now<=v)
					if(k%2)
						ans-=ways[v-now];
					else
						ans+=ways[v-now];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}