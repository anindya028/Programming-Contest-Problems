#include<stdio.h>

int mod;

struct matrix
{
	int mat[20][20];
	int n;
};

matrix mult(matrix A,matrix B)
{
	matrix C;
	C.n=A.n;
	int i,j,k;
	for(i=0;i<A.n;i++)
		for(j=0;j<B.n;j++)
		{
			C.mat[i][j]=0;
			for(k=0;k<A.n;k++)
				C.mat[i][j]=(C.mat[i][j] + (A.mat[i][k] * B.mat[k][j])%mod)%mod;
		}
	return C;
}

matrix power(matrix A,int p)
{
	matrix B;
	if(p==1)
		return A;
	if(p%2==0)
	{
		B=power(A,p/2);
		return mult(B,B);
	}
	else
	{
		B=power(A,p/2);
		B=mult(B,B);
		return mult(A,B);
	}	
}

int main()
{
	int d,n,i,ans,j,ini[20];
	while(scanf("%d%d%d",&d,&n,&mod)==3 && mod)
	{
		matrix now;
		now.n=d;
		for(i=0;i<now.n;i++)
			scanf("%d",&now.mat[0][i]),now.mat[0][i]%=mod;
		for(i=0;i<d;i++)
			scanf("%d",&ini[i]),ini[i]%=mod;
		
		if(n<=d)
		{
			printf("%d\n",ini[n-1]);
			continue;
		}
		
		for(i=1;i<now.n;i++)
			for(j=0;j<now.n;j++)
				now.mat[i][j]= (i-j)==1;
		
		now=power(now,n-d);
		
		for(i=ans=0;i<d;i++)
			ans=(ans + (now.mat[0][i] * ini[d-i-1])%mod)%mod;

		printf("%d\n",ans%mod);
	}
	return 0;
}