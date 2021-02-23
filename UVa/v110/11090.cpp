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
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

double mat[55][55][55];

int main()
{
	int t,T,i,j,k,u,v,n,m,cs;
	double c,mn;
	scanf("%d",&T);
	Foro(cs,T)
	{
		scanf("%d%d",&n,&m);
		Fore(i,1,n)
			Fore(j,1,n)
				Fore(k,1,n)
					mat[i][j][k]=(double)(inf);
		Foro(i,m)
			scanf("%d%d%lf",&u,&v,&c),mat[1][u][v]=Min(mat[1][u][v],c);
		Fore(t,2,n)
			Fore(i,1,n)
				Fore(j,1,n)
					Fore(k,1,n)
						mat[t][i][j]=Min(mat[t][i][j],mat[1][i][k]+mat[t-1][k][j]);
		mn=(double)(inf)+1.;
		Fore(i,1,n)
			Fore(j,1,n)
				if(mat[i][j][j]<inf)
					mn=Min(mn,mat[i][j][j]/i);
		if(mn<inf)
			printf("Case #%d: %.2lf\n",cs+1,mn);
		else
			printf("Case #%d: No cycle found.\n",cs+1);
	}
	return 0;
}