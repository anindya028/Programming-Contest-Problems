#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define Long long long 
enum{left=0,down};
#define size 40
int sq[size][size][2];
Long dp[size][size];

int main()
{
	register int i,j;
	int n,sx,sy,tx,ty,m,u,v,t;
	char s[10];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		for(i=sx;i<=tx;i++)
			for(j=sy;j<=ty;j++)
				dp[i][j]=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				sq[i][j][0]=sq[i][j][1]=1;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%s",&u,&v,s);
			if(s[0]=='S')
				sq[u][v][down]=0;
			else if(s[0]=='W')
				sq[u][v][left]=0;
			else if(s[0]=='N')
				sq[u][v+1][down]=0;
			else
				sq[u+1][v][left]=0;
		}
		dp[sx][sy]=1;
		for(i=sx+1;i<=tx;i++)
			if(sq[i][sy][left])
				dp[i][sy]=dp[i-1][sy];
			else
				dp[i][sy]=0;
		for(i=sy+1;i<=ty;i++)
			if(sq[sx][i][down])
				dp[sx][i]=dp[sx][i-1];
			else
				dp[sx][i]=0;
		for(i=sx+1;i<=tx;i++)
			for(j=sy+1;j<=ty;j++)
			{
				if(sq[i][j][left])
					dp[i][j]+=dp[i-1][j];
				if(sq[i][j][down])
					dp[i][j]+=dp[i][j-1];
			}

		printf("%lld\n",dp[tx][ty]);
	}
	return 0;
}

