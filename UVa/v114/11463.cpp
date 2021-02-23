#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

int mat[105][105];

int main()
{
	int i,j,k,n,m,s,d,mx,t,cs;
	scanf("%d",&t);
	Foro(cs,t)
	{
		scanf("%d%d",&n,&m);
		Foro(i,n)
		{
			Foro(j,n)
				mat[i][j]=inf;
			mat[i][i]=0;
		}
		Foro(i,m)
		{
			scanf("%d%d",&j,&k);
			mat[j][k]=mat[k][j]=1;
		}
		scanf("%d%d",&s,&d);
		Foro(k,n)
			Foro(i,n)
				Foro(j,n)
					mat[i][j]=mat[j][i]=Min(mat[i][j],mat[i][k]+mat[k][j]);
		mx=0;
		Foro(i,n)
			mx=Max(mx,mat[s][i]+mat[i][d]);
		printf("Case %d: %d\n",cs+1,mx);
	}
	return 0;
}
