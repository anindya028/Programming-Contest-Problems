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
	LL mat[5][5],r,c;
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

LL calc_fib(int n)
{
	D.mat[0][0] = D.mat[0][1] = 1;
	D.mat[1][0] = 1; D.mat[1][1] = 0;
	D.r = D.c = 2;
	if(n<2)
		return 1;
	bigmod(n-1);
	return (C.mat[0][0] + C.mat[0][1])%mod;
}

LL calc(LL a,LL b,LL c,LL d)
{
	return a*d - b*c;
}

LL fib[55];

int main()
{
	int i;
	fib[0] = fib[1] = 1;
	for(i=2;i<=52;i++)
		fib[i] = fib[i-1] + fib[i-2];
	
	int t,n,x,m,y,k;
	LL a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&x,&m,&y,&k);
		if(n>50 || m>50)
		{
			puts("Impossible");
			continue;
		}
		LL a1 = fib[n-1],b1 = fib[n],c1 = x,a2 = fib[m-1],b2 = fib[m],c2 = y;
		LL det = calc(a1,b1,a2,b2);
		LL deta = calc(c1,b1,c2,b2);
		LL detb = calc(a1,c1,a2,c2);
		if(deta%det != 0 || detb%det !=0)
		{
			puts("Impossible");
			continue;
		}
		a = deta/det;
		b = detb/det;
		//printf("%lld %lld\n",a,b);
		if(a<0 || b<0)
		{
			puts("Impossible");
			continue;
		}
		if(a==0 && b==0)
		{
			puts("Impossible");
			continue;
		}
		LL ans = (calc_fib(k-1)*a)%mod;
		ans = ( ans + (calc_fib(k)*b)%mod) % mod;
		printf("%lld\n",ans);
	}
	return 0;
}
