//Combinatorics + Easy DP
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

//#define Long __int64
#define Long long long

int main()
{
	int n,dig[15],is[10],c;
	register int i,j;
	Long sum,ans,ten[13],fact[13];
	ten[0]=fact[0]=1;
	for(i=1;i<13;i++)
		ten[i]=ten[i-1]*10,fact[i]=fact[i-1]*i;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<10;++i)
			is[i]=0;
		for(i=j=0;i<n;++i)
		{
			scanf("%d",&dig[i]);
			is[dig[i]]++;
		}
		if(n==1)
		{
			printf("%d\n",dig[0]);
			continue;
		}
		ans=0;
		sum=0;
		for(i=1;i<10;++i)
			if(is[i])
			{
				c=fact[n-1];
					for(j=0;j<10;++j)
						if(j==i && is[j])
							c/=fact[is[j]-1];
						else
							c/=fact[is[j]];
				sum+=c*i;
			}
		for(i=0;i<n;++i)
			ans+=(sum*ten[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
