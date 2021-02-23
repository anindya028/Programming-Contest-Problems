#include<stdio.h>

#define For(i,a,b) for(i=(a);i<=(b);i++)
#define mod 10007
#define mabs(a) ((a)>0?(a):-(a))

int f(int n)
{
	int i,j,k,l,m,sum=0;
	For(i,1,n)
		For(j,1,n)
			For(k,1,n)
				For(l,1,n)
					For(m,1,n)
						sum=(sum + (mabs(i-j)*mabs(j-k)*mabs(k-l)*mabs(l-m)*mabs(m-i)))%mod;
	return sum;
}	

int diff[12][12],fact[12],finv[12];

int powmod(int a,int p,int m)
{
	if(!p)
		return 1;
	if(p%2)
	{
		int b=powmod(a,p-1,m);
		return (a*b)%m;
	}
	else
	{
		int b=powmod(a,p/2,m);
		return (b*b)%m;
	}
}

int ncr(int n,int r)
{
	int ret=1,i;
	for(i=0;i<r;i++)
		ret=(ret*((n-i)%mod))%mod;
	ret=(ret*finv[r])%mod;
	return ret;
}

int main()
{
	int n;
	int i,j;
	for(i=1;i<=11;i++)
	{
		diff[i][0]=f(i);
//		printf("%d\n",diff[i][0]);
	}
	for(j=1;j<=11;j++)
		for(i=1;i<=11-j;i++)
			diff[i][j]=(diff[i+1][j-1] - diff[i][j-1] + mod)%mod;
	fact[0]=1;
	for(i=1;i<11;i++)
		fact[i]=fact[i-1]*i;
	for(i=0;i<=10;i++)
		finv[i]=powmod(fact[i]%mod,mod-2,mod);
	while(scanf("%d",&n)==1 && n)
	{
		int ans=0;
		for(i=0;i<n && i<=10;i++)
			ans = ( ans + ( diff[1][i] * ncr(n-1,i) )%mod ) %mod;
		printf("%d\n",ans);
	}
	return 0;
}