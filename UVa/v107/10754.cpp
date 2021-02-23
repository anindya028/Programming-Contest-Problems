#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int mod;
#define LL long long

struct matrix
{
	LL mat[35][35],r,c;
}A,B,C,D;	//D->the base matrix, we want to compute D^p. C is the result.

void mat_mult_mod()
{
	int i,j,k;					//A.c must be equal to B.r
	for(i=0;i<A.r;i++)
		for(j=0;j<B.c;j++)
		{
			C.mat[i][j]=0;
			for(k=0;k<A.c;k++)
				C.mat[i][j]=(C.mat[i][j]+((A.mat[i][k]%mod)*(B.mat[k][j]%mod))%mod)%mod;
		}
	C.r=A.r;
	C.c=B.c;
}

void bigmod(int p)
{
	if(p==1)
	{
		C=D;
		return;
	}
	if(p%2==0)
	{
		bigmod(p/2);
		A=C;
		B=C;
		mat_mult_mod();
	}
	else
	{
		bigmod(p-1);
		A=C;
		B=D;
		mat_mult_mod();
	}
}

int main()
{
	int t,cs,i,k,n,j;
	LL a[30];
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		scanf("%d%d%d",&k,&mod,&n);
		D.r=D.c=k+1;
		for(i=0;i<D.r;i++)
			for(j=0;j<D.c;j++)
				D.mat[i][j]=0;
		
		for(i=0;i<k;i++)
			scanf("%lld",&D.mat[0][i]),D.mat[0][i]=(D.mat[0][i]%mod+mod)%mod;
		scanf("%lld",&a[i]);
		D.mat[0][i]=1;
		for(i--;i>=0;i--)
			scanf("%lld",&a[i]);
		for(i=0;i<=k;i++)
			a[i]=(a[i]%mod+mod)%mod;
		
		for(i=1;i<k;i++)
			D.mat[i][i-1]=1;
		D.mat[k][k]=1;
		
		if(n<k)
		{
			printf("%lld\n",a[k-1-n]);
			continue;
		}

		bigmod(n-k+1);
		LL ans=0;
		for(i=0;i<=k;i++)
			ans=(ans+(C.mat[0][i]*a[i])%mod)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}