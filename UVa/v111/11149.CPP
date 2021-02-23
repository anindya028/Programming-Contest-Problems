//Recursion
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct matrix
{
	int mat[50][50],r,c;
}a,po,sum;
matrix mat_mult_mod(matrix A,matrix B,int m)
{
	int i,j,k;//A.c must be equal to B.r
	matrix C;
	for(i=0;i<A.r;i++)
		for(j=0;j<B.c;j++)
		{
			C.mat[i][j]=0;
			for(k=0;k<A.c;k++)
				C.mat[i][j]+=(A.mat[i][k]*B.mat[k][j])%m;
			C.mat[i][j]%=m;
		}
	C.r=A.r;
	C.c=B.c;
	return C;
}

matrix add(matrix A,matrix B,int m)
{
	int i,j;
	matrix C;
	for(i=0;i<A.r;i++)
		for(j=0;j<A.c;j++)
			C.mat[i][j]=(A.mat[i][j]+B.mat[i][j])%m;
	C.r=A.r;
	C.c=A.c;
	return C;
}

void make(int n)                            // computes A + A^2 + ... + A^k
{
	//if(!n)return;
	if(n==1)
	{
		po=a;
		sum=a;
		return;
	}
	if(n%2==0)
	{
		make(n/2);
		sum=add(sum,mat_mult_mod(sum,po,10),10);
		po=mat_mult_mod(po,po,10);
		return;
	}
	else
	{
		make(n-1);
		po=mat_mult_mod(po,a,10);
		sum=add(sum,po,10);
	}
	return;
}

int main()
{
	int i,j,k,n;
	while(scanf("%d%d",&n,&k)==2)
	{
		if(!n)break;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				scanf("%d",&a.mat[i][j]);
				a.mat[i][j]%=10;
			}
		a.c=a.r=n;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				sum.mat[i][j]=0;
		make(k);
		for(i=0;i<sum.r;i++)
		{
			printf("%d",sum.mat[i][0]%10);
			for(j=1;j<sum.c;j++)
				printf(" %d",sum.mat[i][j]%10);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}













