#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define myabs(a) (((a)>0)?(a):-(a))
#define inf 10000000.0
#define eps 1e-9
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

double mat[30][30],cum[30][30];

int main()
{
	int r,c,ar,ac,cs=0;
	register int i,j;
	double now,mn;
	while(scanf("%d%d",&r,&c)==2 && r && c)
	{
		For(i,1,r+1)
			For(j,1,c+1)
				scanf("%lf",&mat[i][j]);
		mat[0][0]=0.0;
		For(i,1,r+2)
			mat[i][0]=mat[i][c+1]=0.0;
		For(i,1,c+2)
			mat[0][i]=mat[r+1][i]=0.0;
		r+=2;
		c+=2;
		cum[0][0]=mat[0][0];
		For(i,1,r)
			cum[i][0]=cum[i-1][0]+mat[i][0];
		For(i,1,c)
			cum[0][i]=cum[0][i-1]+mat[0][i];
		For(i,1,r)
			For(j,1,c)
				cum[i][j]=cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1]+mat[i][j];
		mn=inf,ar=-1,ac=-1;
		For(i,1,r-1)
			For(j,1,c-1)
			{
				now=myabs(cum[i-1][c-1]-cum[r-1][c-1]+cum[i][c-1]);
				now+=myabs(cum[r-1][j-1]-cum[r-1][c-1]+cum[r-1][j]);
				if(now<mn || myabs(now-mn)<eps)
				{
					mn=now;
					ar=i;
					ac=j;
				}
			}
		printf("Case %d: center at (%d, %d)\n",++cs,ar,ac);
	}
	return 0;
}