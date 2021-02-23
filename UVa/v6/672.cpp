#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))
#define mab(a) (((a)>0)?(a):-(a))

struct gang
{
	int tg,p,s;
}g[105];

bool operator<(gang a,gang b)
{
	if(a.tg==b.tg)
	{
		if(a.p==b.p)
			return a.s<b.s;
		return a.p<b.p;
	}
	return a.tg<b.tg;
}

int dp[105][105],n;

int make(int pos,int last)
{
	if(pos>n)
		return 0;
	if(dp[pos][last]!=-1)
		return dp[pos][last];
	dp[pos][last]=make(pos+1,last);
	int i;
	if(mab(g[pos].s-g[last].s)<=(g[pos].tg-g[last].tg))
		i=g[pos].p+make(pos+1,pos),
		dp[pos][last]=Max(dp[pos][last],i);
	return dp[pos][last];
}

int main()
{
	int k,t,i,cs,T;
	scanf("%d",&T);
	for(cs=0;cs<T;cs++)
	{
		if(cs)
			printf("\n");
		scanf("%d%d%d",&n,&k,&t);
		g[0].tg=g[0].p=g[0].s=0;
		for(i=1;i<=n;i++)
			scanf("%d",&g[i].tg);
		for(i=1;i<=n;i++)
			scanf("%d",&g[i].p);
		for(i=1;i<=n;i++)
			scanf("%d",&g[i].s);
		mem(dp,-1);
		sort(g,g+n+1);
		printf("%d\n",make(1,0));
	}
	return 0;
}
