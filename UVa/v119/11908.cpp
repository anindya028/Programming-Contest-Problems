#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>

using namespace std;

#define inf (1<<29)
#define mem(a,b) memset(a,(b),sizeof(a))
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b)  ((a) < (b) ? (a) : (b))

typedef pair<int,int> pii;

struct adv
{
	int a,b,c;
}g[30005];

bool operator<(adv x,adv y)
{
	return x.a<y.a;
}

int fr[200005],cum[200005];

int dp[30005],n;
int make(int now)
{
	if(now>=n)
		return 0;
	if(dp[now]!=-1)
		return dp[now];
	dp[now]=make(now+1);
	int v=g[now].c+make(cum[g[now].a+g[now].b-1]);
	dp[now]=Max(dp[now],v);
	return dp[now];
}

int main()
{
	int t,cs=0,i,mx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mem(fr,0);
		mem(cum,0);
		mx=0;
		for(i=0;i<n;i++)
			scanf("%d%d%d",&g[i].a,&g[i].b,&g[i].c),fr[g[i].a]++,mx=Max(mx,g[i].a+g[i].b-1);
		sort(g,g+n);
		
		cum[0]=fr[0];
		for(i=1;i<=mx+2;i++)
			cum[i]=cum[i-1]+fr[i];
		mem(dp,-1);
		printf("Case %d: %d\n",++cs,make(0));
	}
	return 0;
}