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

struct four
{
	int a,b,c,d;
}f[40];

int main()
{
	int i,j,k,l,n=0;	
	for(i=0;i<7;i++)
		for(j=i+1;j<7;j++)
			for(k=j+1;k<7;k++)
				for(l=k+1;l<7;l++)
					f[n].a=i,f[n].b=j,f[n].c=k,f[n].d=l,n++;
	D.r=D.c=n;
	four now;
	for(i=0;i<n;i++)
	{
		now=f[i];
		for(j=0;j<(1<<4);j++)
		{
			int v[4];
			for(k=0;k<4;k++)
				if(j & 1<<k)
					v[k]=1;
				else
					v[k]=-1;
			v[0]+=now.a,v[1]+=now.b,v[2]+=now.c,v[3]+=now.d;
			sort(v,v+4);
			for(k=0;k<n;k++)
				if(f[k].a==v[0] && f[k].b==v[1] && f[k].c==v[2] && f[k].d==v[3])
					D.mat[i][k]=1;
		}
	}
	int t,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		
		int v[4];
		for(i=k=0;i<7;i++)
		{
			scanf("%d",&j);
			if(j!=0)
				v[k++]=i;
		}
		now.a=v[0],now.b=v[1],now.c=v[2],now.d=v[3];
		for(i=0;i<n;i++)
			if(now.a==f[i].a && now.b==f[i].b && now.c==f[i].c && now.d==f[i].d)
			{
				j=i;
				break;
			}
		if(m==1)
		{
			printf("1\n");
			continue;
		}
		bigmod(m-1);
		LL ans=0;
		for(i=0;i<n;i++)
			ans=(ans+C.mat[j][i])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}