#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define Min(a,b) (((a)<(b))?(a):(b))
#define LL long long

char p[1000005];
LL pr[100000];

vector< pair<LL,int> > fact;
vector<LL> factor;

map<LL,int> mp;
LL parent[10005][50];
double dp[10005][50],logp[60];

int gene(int n)
{
	int i,j;
	for(i=2;i*i<=n;i++)
		for(j=i*i;j<=n;j+=i)
			p[j]=1;
	j=0;
	for(i=2;i<=n;i++)
		if(!p[i])
			pr[j++]=i;
	return j;
}

void bktk(LL now,int pos)
{
	if(pos==fact.size())
	{
		factor.push_back(now);
		return;
	}
	bktk(now,pos+1);
	int i;
	for(i=0;i<fact[pos].second;i++)
		now*=fact[pos].first,
		bktk(now,pos+1);
}

double make(LL now,int pos)
{
	if(now==1)
		return 0.0;
	if(pos>35)
		return 1e13;
	int idx=mp[now],i;
	if(dp[idx][pos]>-1)
		return dp[idx][pos];
	dp[idx][pos]=1e13;
	double got;
	for(i=0;i<factor.size() && factor[i]*factor[i]<=now;i++)
		if(now%factor[i]==0)
		{
			LL next=now/factor[i];
			if(next<now)
				got = (factor[i]-1)*logp[pos] + make(next,pos+1);
			else
				got=1e13;
			if(got<dp[idx][pos])
			{
				dp[idx][pos]=got;
				parent[idx][pos]=factor[i]-1;
			}
			got = (next-1)*logp[pos] + make(factor[i],pos+1);
			if(got<dp[idx][pos])
			{
				dp[idx][pos]=got;
				parent[idx][pos]=next-1;
			}
		}
	return dp[idx][pos];
}

#define mod 1000000007

LL powmod(LL a,LL n)
{
	if(n==1)
		return a%mod;
	if(n%2)
	{
		LL g=powmod(a,n-1);
		return (g*a)%mod;
	}
	else
	{
		LL g=powmod(a,n/2);
		return (g*g)%mod;
	}
}

int main()
{
	int t,i,j,m=gene(1000005);
	for(i=0;i<55;i++)
		logp[i]=log((double)pr[i]);
	LL n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		n++;
		
		fact.clear();
		factor.clear();
		mp.clear();
		
		LL temp=n;
		for(i=0;i<m && pr[i]*pr[i]<=temp;i++)
			if(temp%pr[i]==0)
			{
				j=0;
				while(temp%pr[i]==0)
					temp/=pr[i],j++;
				fact.push_back(make_pair(pr[i],j));
			}
		if(temp!=1)
			fact.push_back(make_pair(temp,1));
		bktk(1,0);
		
		sort(factor.begin(),factor.end());
	//	printf("->%lld\n",factor[factor.size()-1]);
	//	if(factor.size()>10000)
	//			while(1);
		for(i=0;i<factor.size();i++)
		{
			mp[factor[i]]=i;
			for(j=0;j<50;j++)
				dp[i][j]=-1.0;
		}

		LL ans=1;
		
		double g=make(n,1);

		i=1;
		while(n>1)
		{
			LL v=parent[mp[n]][i];
			ans = (ans * powmod(pr[i],v))%mod;
			n/=(v+1);
			i++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
