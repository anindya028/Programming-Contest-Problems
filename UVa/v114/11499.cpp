#include<stdio.h>

#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,(a))
#define Max(a,b) (((a)>(b))?(a):(b))

int mat[605][605],pp[605][605];

int main()
{
	int n,m,i,j,k,ans,now;
	while(scanf("%d%d",&n,&m)==2 && n && m)
	{
		Foro(i,n)
			Foro(j,m)
				scanf("%d",&mat[i][j]);
		Foro(i,n)
		{
			pp[i][0]=0;
			For(j,1,m)
				if(mat[i][j]>mat[i][j-1])
					pp[i][j]=pp[i][j-1]+1;
				else
					pp[i][j]=0;
			pp[i][j]=0;
		}
		ans=0;
		Foro(i,m)
			For(j,i,m)
			{
				now=k=0;
				while(k<n)
				{
					while(k<n && (pp[k][j]-pp[k][i]+1)==(j-i+1) && (k==now || mat[k][i]>mat[k-1][j]))
						k++;
					ans=Max(ans,(k-now)*(j-i+1));
					while(k<n && (pp[k][j]-pp[k][i]+1)!=(j-i+1))
						k++;
					now=k;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}