#include<stdio.h>

#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,(a))

double mat[55][105][105];

double make(int N,int m,int n)
{
	if(m==-1 || n==-1)
		return 0.;
	if(!N)
		return 1.;
	if(mat[N][m][n]>-1.)
		return mat[N][m][n];
	mat[N][m][n]=.25*(make(N-1,m-1,n+1)+make(N-1,m+1,n-1));
	if(m>0)mat[N][m][n]+=.25*make(N-1,m,n);
	if(n>0)mat[N][m][n]+=.25*make(N-1,m,n);
	return mat[N][m][n];
}

int main()
{
	int t,N,m,n,i,j,k;
	Foro(i,104)
		Foro(j,104)
			Foro(k,53)
				mat[k][i][j]=-1.;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&N,&m,&n);
		printf("%.6lf\n",make(N,m,n));
	}
	return 0;
}
