#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

struct item
{
	int p,f;
}g[105];

bool operator<(item a,item b)
{
	if(a.p==b.p)
		return a.f<b.f;
	return a.p<b.p;
}

int dp[12000];

int main()
{
	int m,n,i,j;
	while(scanf("%d%d",&m,&n)==2)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&g[i].p,&g[i].f);
		
		sort(g,g+n);

		for(i=1;i<=m+205;i++)
			dp[i]=-1;
		dp[0]=0;
		for(i=0;i<n;i++)
			for(j=m+200;j>=0;j--)
				if(dp[j]>=0 && (j+g[i].p<=m || (j+g[i].p<=m+200 && j+g[i].p>2000)))
					if(dp[j]+g[i].f>dp[j+g[i].p])
						dp[j+g[i].p]=dp[j]+g[i].f;
		j=-1;
		for(i=0;i<=m+200;i++)
			if(dp[i]>j)
				j=dp[i];
		printf("%d\n",j);
	}
	return 0;
}