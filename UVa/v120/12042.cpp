#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define mod 1000000007
#define LL long long

struct matrix
{
	LL mat[105][105],r,c;
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
	int n,i,p,t,j;
	int a[105];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(D.mat,0,sizeof(D.mat));
		D.r = D.c = n;
		for(i=n-1;i>=0;i--)
		{
			D.mat[i][n-1] = 1;
			for(j=0;j<i;j++)
				D.mat[i][j] = 1;
		}
		if(p>1)
			bigmod(p-1);
		for(i=0;i<n;i++)
		{
			LL sum = 0;
			if(p>1)
				for(j=0;j<n;j++)
					sum = (sum + (C.mat[i][j]*a[j])%mod)%mod;
			else
				sum = a[i];
			if(i)
				printf(" ");
			printf("%lld",sum);
		}
		printf("\n");
	}
	return 0;
}