#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64
#define Long long long 
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
matrix bigmod(matrix B,Long p,int m)
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
	Long n;
	int b,cs=0;
	fib.mat[0][0]=1;
	fib.mat[1][0]=1;
	fib.mat[0][1]=1;
	fib.mat[1][1]=0;
	fib.c=2;
	fib.r=2;
	matrix ans;
	while(scanf("%lld%d",&n,&b)==2)
	{
		if(!n && !b)break;
		if(!n)
		{
			printf("Case %d: %lld %d %d\n",++cs,n,b,(1%b));
			continue;
		}
		if(n==1)
		{
			printf("Case %d: %lld %d %d\n",++cs,n,b,(1%b));
			continue;
		}
		ans=bigmod(fib,n,b);
		if(ans.mat[0][0]==0)ans.mat[0][0]=b;
		printf("Case %d: %lld %d %d\n",++cs,n,b,(2*ans.mat[0][0]-1)%b);
	}
	return 0;
}













