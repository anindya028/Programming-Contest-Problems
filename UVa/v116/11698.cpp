/*
Combinatorics + Number Theory
Very Good problem
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
LL mod;

vector<int> fact;
int k;
map<int,int> mp;

LL ncr[105][105];

LL C(int n,int r)
{
	if(!r || n==r) return 1;
	if(ncr[n][r]!=-1)
		return ncr[n][r];
	ncr[n][r]=(C(n-1,r)+C(n-1,r-1))%mod;
	return ncr[n][r];
}

int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,(a%b));
}

int lcm(int a,int b)
{
	return (a/gcd(a,b))*b;
}

LL modpow(LL b,int p)
{
	if(!p)
		return 1;
	if(p%2)
	{
		LL a=modpow(b,p-1);
		return (a*b)%mod;
	}
	else
	{
		LL a=modpow(b,p/2);
		return (a*a)%mod;
	}
}

LL dp[102][515][42];
LL f[105];
LL finv[105];

LL make(int rem,int now,int last)
{
	if(!rem)
		return (fact[now]==k);
	if(last>=fact.size() || fact[last]>rem)
		return 0;
	if(dp[rem][now][last]!=-1)
		return dp[rem][now][last];
	dp[rem][now][last]=0;
	int i,j,u=0,w;
	int next = mp[lcm(fact[now],fact[last])];
	LL v, prev = 1;
	for(i = w =0;i <= rem;i += fact[last], w++)
	{
		if(!i)
			j = now;
		else
			j = next;
		if(!i)
			v = 1;
		else
			prev = ( prev * ( (C(rem-u,fact[last]) * f[fact[last]-1] )%mod) )%mod,
			v=(prev*finv[w])%mod,
			u+=fact[last];
		
		dp[rem][now][last]=(dp[rem][now][last] + ((v * make(rem-i,j,last+1))%mod) )%mod;
	}
	return dp[rem][now][last];
}

int main()
{
	int t,n;
	LL i;
	mod=2147483647;
	mem(ncr,-1);
	scanf("%d",&t);
	f[0]=1;
	for(i=1;i<=101;i++)
	{
		f[i]=(f[i-1]*i)%mod;
		finv[i]=modpow(f[i],mod-2);
	}
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(k==1)
		{
			printf("1\n");
			continue;
		}
		fact.clear();
		mp.clear();
		for(i=1;i*i<=k;i++)
			if(k%i==0)
			{
				fact.push_back(i);
				if(i!=(k/i))
					fact.push_back(k/i);	
			}
		sort(fact.begin(),fact.end());
		for(i=0;i<fact.size();i++)
			mp[fact[i]]=i;
		mem(dp,-1);
		LL ans=0;
		printf("%lld\n",make(n,0,0));
	}
	return 0;
}