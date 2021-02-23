#include<stdio.h>

int mat[10005][35];

int gcd(int n,int m)
{
	if(!m) return n;
	return gcd(m,(n%m));
}

int main()
{
	int i,j,n,m,sum;
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		for(i=sum=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				scanf("%d",&mat[i][j]);
			sum+=mat[i][m-1];
		}
		for(i=0;i<n;i++)
		{
			j=gcd(mat[i][m-1],sum);
			printf("%d / %d\n",mat[i][m-1]/j,sum/j);
		}
	}
	return 0;
}