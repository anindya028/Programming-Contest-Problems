#include<stdio.h>
#include<algorithm>

using namespace std;

#define LL long long
#define mod 1000000007

int data[100005],n;

LL tree[100005];

LL read(int idx)
{
	LL mul=1;
	while(idx>0)
		mul=(mul*tree[idx])%mod,
		idx-=(idx & -idx);
	return mul;
}

void update(int idx,int val)
{
	while(idx<=n)
		tree[idx]=(tree[idx]*val)%mod,
		idx+=(idx & -idx);
}

LL modpow(int b,int p)
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

int main()
{
	int i,t,q,u,v,is;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tree[0]=1;
		for(i=0;i<n;i++)
		{
			scanf("%d",&data[i]);
			tree[i+1]=1;
			if(data[i]<=0)
				printf("%d",data[-1]);
		}
		for(i=0;i<n;i++)
			update(i+1,data[i]);
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			scanf("%d%d%d",&is,&u,&v);
			if(!is)
			{
				LL ans=read(v);
				LL a=read(u-1);
				LL b=modpow(a,mod-2);
				ans=(ans*b)%mod;
				printf("%lld\n",ans);
			}
			else
			{
				LL a=modpow(data[u-1],mod-2);
				update(u,a);
				update(u,v);
				data[u-1]=v;
			}
		}
	}
	return 0;
}