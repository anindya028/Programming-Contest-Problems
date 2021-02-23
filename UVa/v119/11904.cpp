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
#define Min(a,b)  ((a) < (b) ? (a) : (b)
#define mod 1000000007
#define LL long long

LL powmod(LL b,int p)
{
	if(!p)
		return 1;
	if(p%2)
		return (b*powmod(b,p-1))%mod;
	else
	{
		LL v=powmod(b,p/2);
		return (v*v)%mod;
	}
}

LL fact[1000005],finv[1000005];

LL ncr(int n,int r)
{
	if(r<0)return 0;
	LL ret=(fact[n]*finv[r])%mod;
	return (ret*finv[n-r])%mod;
}

int a[1005];

int main()
{
	int i=0,n,sum;
	LL ans;
	fact[i]=1,finv[i]=1;
	for(i=1;i<=1000002;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		finv[i]=powmod(fact[i],mod-2);
	}
	int t,cs;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		ans=1,sum=a[0];
		for(i=1;i<n;i++)
		{
			ans=(ans*ncr(sum+a[i]-1,a[i]-1))%mod;
			sum+=a[i];
		}
		printf("Case %d: %lld\n",cs+1,ans);
	}
	return 0;
}