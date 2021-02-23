#include<stdio.h>
#include<stdlib.h>

#define inf 100000000
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,a)

int mat[10][10],dp[1<<9][1<<9],n;

int make(int nowa,int nowb)
{
	if(nowa==((1<<(n))-1))
		return 0;
	if(dp[nowa][nowb]>-inf)
		return dp[nowa][nowb];
	int i,j,mn,mx=-inf,t;
	Foro(i,n)
		if(!(nowa & 1<<i))
		{
			mn=inf;
			Foro(j,n)
				if(!(nowb & 1<<j))
					t=make(nowa | 1<<i,nowb | 1<<j),
					mn=Min(mn,mat[i][j]+t);
			mx=Max(mx,mn);
		}
	dp[nowa][nowb]=mx;
	return dp[nowa][nowb];
}

int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		Foro(i,n)
			Foro(j,n)
				scanf("%d",&mat[i][j]);
		Foro(i,1<<n)
			Foro(j,1<<n)
				dp[i][j]=-inf;
		printf("%d\n",make(0,0));
	}
	return 0;
}