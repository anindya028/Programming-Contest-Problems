#include<stdio.h>

#define LL long long

LL bigmod(LL b,LL p,LL m)
{
	if(p==0)
		return 1%m;
	LL ret = bigmod(b,p/2,m);
	ret = (ret*ret)%m;
	if(p%2)
		ret = (ret*b)%m;
	return ret;
}

char p[1000005];
int pr[80000];

int gene(int n)
{
	int i,j;
	for(i = 2; i*i <= n; i++)
		if(!p[i])
			for(j=i*i;j<=n;j+=i)
				p[j] = 1;
	j = 0;
	for(i=2;i<=n;i++)
		if(!p[i])
			pr[j++] = i;
	return j;
}

int main()
{
	int cs,T,m = gene(1000000),i,n,t;
	LL mod = 10000019;
	scanf("%d",&T);
	for(cs=1;cs<=T;cs++)
	{
		scanf("%d%d",&n,&t);
		int got = 0;
		LL res = 1;
		for(i = 0; pr[i] <= n && i<m; i++)
		{
			int cnt = 0;
			int v = n;
			while(v)
				cnt += v/= pr[i];
			if(cnt>=t)
				got = 1;
			res = ( res * bigmod(pr[i], cnt/t, mod))%mod;
		}
		if(got)
			printf("Case %d: %lld\n",cs,res);
		else
			printf("Case %d: -1\n",cs);
	}
	return 0;
}

