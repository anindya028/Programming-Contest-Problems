#include<stdio.h>

#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,(a))
#define mod 1000000007

long long ncr[1005][1005],de[1005][1005],fact[1005],ans;

long long comb(int n,int k)
{
	if(!k || n==k)
		return 1;
	if(ncr[n][k]!=-1)
		return ncr[n][k];
	ncr[n][k]=(comb(n-1,k)+comb(n-1,k-1))%mod;
	return ncr[n][k];
}

long long dearr(int n,int m)
{
	if(m<0)
		return 0;
	if(!m)
		return fact[n];
	if(de[n][m]!=-1)
		return de[n][m];
	de[n][m]=((m-1)*dearr(n-1,m-2))%mod;
	de[n][m]=(de[n][m]+((n-m)*dearr(n-1,m-1))%mod)%mod;
	return de[n][m];
}

int main()
{
	int i,j,n,m,k,t,cs;
	Foro(i,1003)
		Foro(j,1003)
			ncr[i][j]=de[i][j]=-1;
	fact[0]=1;
	For(i,1,1003)
		fact[i]=(fact[i-1]*i)%mod;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d%d%d",&n,&m,&k);
		ans=(comb(m,k)*dearr(n-k,m-k))%mod;
		printf("Case %d: %lld\n",cs+1,ans);
	}
	return 0;
}