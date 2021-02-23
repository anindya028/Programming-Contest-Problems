#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct matrix
{
	int mat[5][5],r,c;
}fib;
matrix mat_mult_mod(matrix A,matrix B,int m)
{
	int i,j,k;//A.c must be equal to B.r
	matrix C;
	for(i=0;i<A.r;i++)
		for(j=0;j<B.c;j++)
		{
			C.mat[i][j]=0;
			for(k=0;k<A.c;k++)
				C.mat[i][j]+=((A.mat[i][k]%m)*(B.mat[k][j]%m))%m;
			C.mat[i][j]%=m;
		}
	C.r=A.r;
	C.c=B.c;
	return C;
}
matrix bigmod(matrix B,int p,int m)
{
	matrix A;
	if(p==1)
		return B;
	if(p%2==0)
	{
		A=bigmod(B,p/2,m);
		return mat_mult_mod(A,A,m);
	}
	else
		return mat_mult_mod(B,bigmod(B,p-1,m),m);
}
int main()
{
	int a,b,n,m,t,i,ten[6];
	for(ten[0]=1,i=1;i<6;i++)
		ten[i]=ten[i-1]*10;
	matrix ans,temp;
	fib.mat[0][0]=0;
	fib.mat[1][0]=1;
	fib.mat[0][1]=1;
	fib.mat[1][1]=1;
	fib.c=fib.r=2;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d%d",&a,&b,&n,&m);
		temp.mat[0][0]=a;
		temp.mat[1][0]=b;
		temp.mat[0][1]=b;
		temp.mat[1][1]=a+b;
		temp.c=temp.r=2;
		if(!n)
		{
			printf("%d\n",a%ten[m]);
			continue;
		}
		if(n==1)
		{
			printf("%d\n",b%ten[m]);
			continue;
		}
		ans=bigmod(fib,n,ten[m]);
		ans=mat_mult_mod(ans,temp,ten[m]);
		printf("%d\n",ans.mat[0][0]%ten[m]);
	}
	return 0;
}
