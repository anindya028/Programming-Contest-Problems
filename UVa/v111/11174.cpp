#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define mod 1000000007
#define LL long long

LL fact[40005],finv[40005];
vector<int> adj[40005];
LL deg[40005],dp[40005],cnt[40005];

LL powmod(LL b, LL p)
{
	if(p==1)
		return (b%mod);
	LL ret = powmod(b,p/2);
	ret = (ret*ret)%mod;
	if(p & 1)
		ret = (ret*b)%mod;
	return ret;
}

void dfs(int now)
{
	int i;
	dp[now] = 1;
	cnt[now] = 0;
	for(i=0;i<adj[now].size();i++)
	{
		dfs(adj[now][i]);
		cnt[now] += cnt[adj[now][i]];
		dp[now] = (dp[now]*dp[adj[now][i]])%mod;
		dp[now] = (dp[now]*finv[cnt[adj[now][i]]])%mod;
	}
	dp[now] = (dp[now]*fact[cnt[now]])%mod;
	cnt[now]++;
}

int main()
{
	int t,n,m,i,a,b;
	fact[0] = 1, finv[0] = 1;
	for(i=1;i<=40002;i++)
		fact[i] = (fact[i-1]*i)%mod,
		finv[i] = powmod(fact[i],mod-2);

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
			adj[i].clear(),deg[i] = 0;

		for(i=0;i<m;i++)
			scanf("%d%d",&a,&b),
			adj[b].push_back(a),
			deg[a]++;

		for(i=1;i<=n;i++)
			if(!deg[i])
				adj[0].push_back(i);

		dfs(0);
		printf("%lld\n",dp[0]);
	}
	return 0;
}