#include<stdio.h>

struct matrix
{
	int mat[52][52],r,c;
}now,A[50],B[50];

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
	int n,i,j,t,p,k,ans[60],m,given[55];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",&given[i]);
		now.r=now.c=n;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				now.mat[i][j]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&p);
			for(j=0;j<p;j++)
				scanf("%d",&k),now.mat[i][k]=1;
		}
		now=bigmod(now,m,1000);
		for(i=0;i<n;i++)
		{
			ans[i]=0;
			for(j=0;j<n;j++)
				ans[i]=(ans[i] + ((given[j]%1000)*now.mat[i][j])%1000 )%1000;
		}
		printf("%d",ans[0]);
		for(i=1;i<n;i++)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
